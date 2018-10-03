#include "string.h"
#include <iostream>
int main() {
	String a("hello");
	String b(a);
	a = "adiossssssss";
	printf("%s\n",b.getString());
	printf("%s\n",a.getString());
	system("Pause");
}
