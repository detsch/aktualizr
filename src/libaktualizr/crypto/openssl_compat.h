#ifndef AKTUALIZR_OPENSSL_COMPAT_H
#define AKTUALIZR_OPENSSL_COMPAT_H

#include <openssl/opensslv.h>

#ifndef OPENSSL_VERSION_NUMBER
#error "OPENSSL_VERSION_NUMBER is not defined"
#endif

#define AKTUALIZR_OPENSSL_PRE_11 (OPENSSL_VERSION_NUMBER < 0x10100000)

#define AKTUALIZR_OPENSSL_AFTER_11 (!AKTUALIZR_OPENSSL_PRE_11)

// PKCS#11 support avoids the ENGINE API (removed in OpenSSL 4.0) on OpenSSL >= 3.0, where curl can
// use the pkcs11-provider for TLS keys. OpenSSL < 3.0 has no providers and keeps the ENGINE path.
#define AKTUALIZR_OPENSSL_PROVIDERS (OPENSSL_VERSION_NUMBER >= 0x30000000L)

#endif  // AKTUALIZR_OPENSSL_COMPAT_H
