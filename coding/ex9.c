void change(char &c) {
  c = 'X';
}
int main() {
  char c = 'R';
  change(&c);
  printf("%c\n",c);
  return 0;
}