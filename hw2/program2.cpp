#include <cstdio>
#include <cstdlib>
#define MAX_STOCK_COUNT 256
#define MAX_PRODUCT_TYPE 256

class Company {
private:
  short *product;
  short unique_stocked;

public:
  Company() {
    product = (short*) calloc(MAX_PRODUCT_TYPE, sizeof(short));
    unique_stocked = 0;
  }
  ~Company() {
    free(product);
  }
  char is_product_exist(short id) {
    if (id < 0 || id >= MAX_PRODUCT_TYPE) return 0;
    return 1;
  }
  short get_product_count(short id) {
    return product[id];
  }
  void check_in(short id, short count) {
    while (count--) check_in(id);
  }
  void check_in(short id) {
    if (!is_product_exist(id)) return;
    if (product[id] >= MAX_STOCK_COUNT) return;
    if (product[id] == 0) unique_stocked++;
    product[id]++;
  }
  void check_out(short id, short count) {
    while (count--) check_out(id);
  }
  void check_out(short id) {
    if (!is_product_exist(id)) return;
    if (product[id] <= 0) return;
    product[id]--;
    if (product[id] == 0) unique_stocked--;
  }
  short get_unique_stocked() {
    return unique_stocked;
  }
};

int main() {
  Company c = Company();
  printf("number of stocked products: %d\n", c.get_unique_stocked());
  printf("\n");

  printf("product 3 %s\n", c.is_product_exist(3) ? "exists" : "does not exist");
  c.check_in(3);
  printf("product 3 checked in\n");
  printf("number of stocked products: %d\n", c.get_unique_stocked());
  printf("\n");

  printf("product -1 %s\n", c.is_product_exist(-1) ? "exists" : "does not exist");
  c.check_in(-1);
  printf("-1 checked in but nothing happens\n");
  printf("number of stocked products: %d\n", c.get_unique_stocked());
  printf("\n");

  c.check_in(3);
  printf("another product 3 checked in\n");
  printf("product 3 stock count %d\n", c.get_product_count(3));
  printf("number of stocked products: %d\n", c.get_unique_stocked());
  printf("\n");

  printf("product 255 %s\n", c.is_product_exist(255) ? "exists" : "does not exist");
  c.check_in(255, 254);
  printf("product 255 checked in 254 times\n");
  printf("product 255 stock count %d\n", c.get_product_count(255));
  printf("number of stocked products: %d\n", c.get_unique_stocked());
  printf("\n");

  printf("product 255 checked out 256 times, but it only did it 254 times\n");
  c.check_out(255, 256);
  printf("product 255 stock count %d\n", c.get_product_count(255));
  printf("number of stocked products: %d\n", c.get_unique_stocked());
  printf("\n");
}
