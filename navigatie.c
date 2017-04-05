void navigate() {
  if (matrix_x > 0){
    switch (direction_faced) {
      case front:
        turn(right);
        break;
      case left:
        turn(back);
        matrix_x++;
        break;
      case right:
        turn(front);
        break;
      case back:
        turn(left);
        break;
    }
    direction_faced = right;
    matrix_x--;
  }
//  else if (matrix_y > 0) {
    //turn(front);
    //matrix_y--;
  //}
  else {
    motor[leftMotor] = 0;
    motor[rightMotor] = 0;
  }
}
