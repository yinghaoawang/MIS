#include <cstdio>
#include <cstdlib>
#define MAX_CLASS_SEATS 256

/* classroom class, seats keeps track of the seats filled by
 * student id which is represented by the index */
class Classroom {
private:
  char* Seat; // 1 for occupied, 0 for not, uses char because small
  short occupant_count; // keeps track of people seated

public:
  Classroom() {
    Seat = (char*) calloc(MAX_CLASS_SEATS, sizeof(char));
    occupant_count = 0;
  }
  ~Classroom() { free(Seat); }
  void check_in(short id) {
    if (id < 0 || id >= MAX_CLASS_SEATS) return;
    if (Seat[id] == 0) {
      occupant_count++;
      Seat[id] = 1;
    }
  }
  void check_out(short id) {
    if (id < 0 || id >= MAX_CLASS_SEATS) return;
    if (Seat[id] != 0) {
      occupant_count--;
      Seat[id] = 0;
    }
  }
  char is_occupied(short id) {
    if (id < 0 || id >= MAX_CLASS_SEATS) return -1;
    return Seat[id];
  }
  short get_available_seats() {
    return MAX_CLASS_SEATS - occupant_count;
  }
};

int main() {
  Classroom cr = Classroom();
  printf("available seats: %d\n", cr.get_available_seats());
  cr.check_in(42);
  printf("42 checked in\n");
  cr.check_in(23);
  cr.check_in(23);
  cr.check_in(23);
  printf("23 checked in 3 times (but only counts once)\n");
  cr.check_in(35);
  printf("35 checked in\n");
  printf("available seats: %d\n", cr.get_available_seats());
  printf("seat 23 is %s\n", cr.is_occupied(23) ? "occupied" : "not occupied");
  printf("seat 35 is %s\n", cr.is_occupied(35) ? "occupied" : "not occupied");
  cr.check_out(23);
  cr.check_out(23);
  cr.check_out(23);
  printf("23 checked out 3 times (but only counts once)\n");
  printf("available seats: %d\n", cr.get_available_seats());
  printf("seat 23 is %s\n", cr.is_occupied(23) ? "occupied" : "not occupied");
  printf("seat 35 is %s\n", cr.is_occupied(35) ? "occupied" : "not occupied");

  return 0;
}
