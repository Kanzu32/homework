int a = 5;
int &b = a;
int *c = &a;
void func (int &b) {
	b += 5;
}