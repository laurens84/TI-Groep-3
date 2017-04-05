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
else if (matrix_y > 1) {
  switch (direction_faced) {
    case front:
      turn(front);
      break;
    case left:
      turn(right);
      break;
    case right:
      turn(left);
      break;
    case back:
      turn(back);
      matrix_y++;
      break;
  }
direction_faced = front;
matrix_y--;
}
  else {
    motor[leftMotor] = 0;
    motor[rightMotor] = 0;
    startTask(playSecret);
  }
}
