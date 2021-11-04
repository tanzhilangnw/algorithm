#include <openssl/bio.h>
#include <openssl/pem.h>
#include <openssl/err.h>
#include <openssl/evp.h>
#include <openssl/pkcs7.h>
#include <openssl/x509.h>
#include <ctype.h>
#include <cstring>
#include <iostream>

using namespace std;

const char CACertificate[] = "\
-----BEGIN CERTIFICATE----- \n\
MIIB/zCCAaagAwIBAgIJAKKa0PAt9M1FMAoGCCqBHM9VAYN1MFsxCzAJBgNVBAYT \n\
AkNOMQ4wDAYDVQQIDAVIdUJlaTEOMAwGA1UEBwwFV3VIYW4xDTALBgNVBAoMBEhV \n\
U1QxDDAKBgNVBAsMA0NTRTEPMA0GA1UEAwwGY2Fyb290MB4XDTIwMDkyMDIwNTkx \n\
OVoXDTMwMDkxODIwNTkxOVowWzELMAkGA1UEBhMCQ04xDjAMBgNVBAgMBUh1QmVp \n\
MQ4wDAYDVQQHDAVXdUhhbjENMAsGA1UECgwESFVTVDEMMAoGA1UECwwDQ1NFMQ8w \n\
DQYDVQQDDAZjYXJvb3QwWTATBgcqhkjOPQIBBggqgRzPVQGCLQNCAASJ8mm28JJR \n\
bZKLr6DCo1+KWimpKEsiTfZM19Zi5ao7Au6YLosyN71256MWmjwkwXxJeLa0lCfm \n\
kF/YWCX6qGQ0o1MwUTAdBgNVHQ4EFgQUAL5hW3RUzqvsiTzIc1gUHeK5uzQwHwYD \n\
VR0jBBgwFoAUAL5hW3RUzqvsiTzIc1gUHeK5uzQwDwYDVR0TAQH/BAUwAwEB/zAK \n\
BggqgRzPVQGDdQNHADBEAiAaZMmvE5zzXHx/TBgdUhjtpRH3Jpd6OZ+SOAfMtKxD \n\
LAIgdKq/v2Jkmn37Y9U8FHYDfFqk5I0qlQOAmuvbVUi3yvM= \n\
-----END CERTIFICATE----- \n\
";

const char pkeyB[] = "\
-----BEGIN EC PARAMETERS----- \n\
BggqgRzPVQGCLQ== \n\
-----END EC PARAMETERS----- \n\
-----BEGIN EC PRIVATE KEY----- \n\
MHcCAQEEINQhCKslrI3tKt6cK4Kxkor/LBvM8PSv699Xea7kTXTToAoGCCqBHM9V \n\
AYItoUQDQgAEH7rLLiFASe3SWSsGbxFUtfPY//pXqLvgM6ROyiYhLkPxEulwrTe8 \n\
kv5R8/NA7kSSvcsGIQ9EPWhr6HnCULpklw== \n\
-----END EC PRIVATE KEY----- \n\
";

int test(int ok, X509_STORE_CTX *ctx) {//检验,防止证书为空 
	return ok;
}

X509 *readX509cert(const char *cert) {
	BIO *bio;
	bio = BIO_new(BIO_s_mem());
	BIO_puts(bio, cert);
    return PEM_read_bio_X509(bio, NULL, NULL, NULL);
}
EVP_PKEY *readkey(const char *private_key) {
	BIO *bio_pkey = BIO_new_mem_buf((char *)private_key, strlen(private_key));
	if (bio_pkey == NULL)
		return NULL;
 	return PEM_read_bio_PrivateKey(bio_pkey, NULL, NULL, NULL);
}

int len;
char out[10010], message[10010];
char *s = message;

bool figure() {
    BIO *bio_in = 0,*bio_out = 0;
	X509_STORE *content = X509_STORE_new();
	X509_STORE_CTX *content_ctx = X509_STORE_CTX_new();
	PKCS7 *p7 = 0;
	ERR_load_crypto_strings();
	OpenSSL_add_all_algorithms();
	if(!(bio_in = BIO_new_fd(fileno(stdin), BIO_NOCLOSE)))
		return false;
	if(!(p7 = PEM_read_bio_PKCS7(bio_in, 0, 0, 0)))
		return false;
	X509_STORE_add_cert(content, readX509cert(CACertificate));
	X509_STORE_set_verify_cb_func(content, test);
	STACK_OF(PKCS7_SIGNER_INFO)*sk = 0;
	PKCS7_SIGNER_INFO *si;
	bio_out = PKCS7_dataDecode(p7, readkey(pkeyB), 0, 0);
	int srclen = BIO_read(bio_out, out, sizeof(out));
	if (srclen > 0)
		out[srclen] = 0;
	else
		return false;
	if(sk = PKCS7_get_signer_info(p7)) {
        int cnt = sk_PKCS7_SIGNER_INFO_num(sk);
        for(int i = 0; i < cnt; ++i) {
            si = sk_PKCS7_SIGNER_INFO_value(sk, i);
            if(PKCS7_dataVerify(content, content_ctx, bio_out, p7, si) <= 0)
                return false;
        }
	}
    return true;
}

int main() {
    if(figure())
        puts(out);
    else
        puts("ERROR");
	return 0;
}
