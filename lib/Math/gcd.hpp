int gcd(int a, int b) {
  int greater = max(a, b), less = min(a, b);
  int remainder = greater % less;

  if(remainder == 0) {
    return less;
  } else {
    return gcd(less, remainder);
  }
}