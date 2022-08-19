#include <cifuzz/cifuzz.h>
#include "polarssl/x509_crt.h"

FUZZ_TEST_SETUP() {
  // Perform any one-time setup required by the FUZZ_TEST function.
}

FUZZ_TEST(const uint8_t *data, size_t size) {
  x509_crt certificate;
  x509_crt_init(&certificate);
  x509_crt_parse_der(&certificate, (unsigned char*)data, size);
  x509_crt_free(&certificate);
}
