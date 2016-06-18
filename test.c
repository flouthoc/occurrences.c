
#include <stdlib.h>
#include "describe/describe.h"
#include "occurrences.h"

int
main(void) {
  describe("occurrences") {
    it("should return -1 when given bad inputs") {
      assert(-1 == (int) occurrences(NULL, NULL, 0));
      assert(-1 == (int) occurrences("foo", NULL, 0));
      assert(-1 == (int) occurrences(NULL, "bar", 0));
    }

    it("should count the number of occurrences in haystack") {
      assert(2 == (int) occurrences("l", "hello", 0));
      assert(1 == (int) occurrences("foo", "foo", 0));
    }

    it("should handle anti-cases") {
      assert(0 == (int) occurrences("foo", "bar", 0));
    }

    it("should not be case-sensitive") {
      assert(2 == (int) occurrences("foo", "foo FOO", 1));
    }

  }

  return assert_failures();
}
