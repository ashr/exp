int f(char x, int y) {}

int g(char a, char b, char c) {}

typedef struct struct_name {
	char x;
	int y;
} struct_type;

typedef enum enum_name {
	A = 1,
	B = 2,
} enum_type;

int h(struct_type *d, enum_type e) {}
