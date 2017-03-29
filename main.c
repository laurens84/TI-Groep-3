#include "Robot.h"

task main() {
  while (1) {
    collision();
    Aandrijving(leftSensor(), rightSensor());
  }
}
