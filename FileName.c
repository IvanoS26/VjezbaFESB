#include <stdio.h>
#include <stdlib.h>

struct polinom {
	int koeficjent;
	int potencija;
	struct polinom* Next;
};

int SortiraniUnos(int koe, int pot, struct polinom* p);
int Ispis(struct polinom* p);

int ZbrojiPolinome(struct polinom* p, struct polinom* q, struct polinom *suma);
int PomnoziPolinome(struct polinom* p, struct polinom* q, struct polinom* produkt);

int main() {

	struct polinom Head1, Head2, Suma, Produkt;
	Head1.Next = NULL;
	Head2.Next = NULL;
	Suma.Next = NULL;
	Produkt.Next = NULL;

	SortiraniUnos(10, 3, &Head1);
	SortiraniUnos(-10, 0, &Head1);
	SortiraniUnos(-10, 323, &Head1);
	SortiraniUnos(10, 1, &Head1);
	SortiraniUnos(0, 123, &Head1);
	Ispis(&Head1);

	SortiraniUnos(10, 3, &Head2);
	SortiraniUnos(-10, 0, &Head2);
	SortiraniUnos(-10, 323, &Head2);
	SortiraniUnos(10, 1, &Head2);
	SortiraniUnos(0, 123, &Head2);
	Ispis(&Head2);

	ZbrojiPolinome(&Head1, &Head2, &Suma);
	Ispis(&Suma);

	PomnoziPolinome(&Head1, &Head2, &Produkt);
	Ispis(&Produkt);

	return 0;
}

int Ispis(struct polinom* p) {

	printf("Polinom:");
	int i = 0;

	while (p->Next != NULL) {

		if (p->Next->potencija != 0) {
			if (p->Next != NULL && p->Next->koeficjent > 0 && i != 0 && p->Next->koeficjent != 0) {
				printf(" + ");
			}
			if (p->Next != NULL && p->Next->koeficjent < 0 && p->Next->koeficjent != 0) {
				printf(" - ");
			}

			if (p->Next != NULL && p->Next->koeficjent > 0 && p->Next->koeficjent != 0) {
				printf("%dx^%d", p->Next->koeficjent, p->Next->potencija);
			}
			if (p->Next != NULL && p->Next->koeficjent < 0 && p->Next->koeficjent != 0) {
				printf("%dx^%d", p->Next->koeficjent * -1, p->Next->potencija);
			}
		}
		else {
			if (p->Next != NULL && p->Next->koeficjent > 0 && i != 0 && p->Next->koeficjent != 0) {
				printf(" + ");
			}
			if (p->Next != NULL && p->Next->koeficjent < 0 && p->Next->koeficjent != 0) {
				printf(" - ");
			}

			if (p->Next != NULL && p->Next->koeficjent > 0 && p->Next->koeficjent != 0) {
				printf("%d", p->Next->koeficjent);
			}
			if (p->Next != NULL && p->Next->koeficjent < 0 && p->Next->koeficjent != 0) {
				printf("%d", p->Next->koeficjent * -1);
			}
		}

		i++;
		p = p->Next;
	}

	printf("\n");

	return 0;
}

SortiraniUnos(int koe, int pot, struct polinom* p) {

	while (p->Next != NULL && p->Next->potencija > pot ) {
		p = p->Next;
	}

	struct polinom* q = (struct polinom*)malloc(sizeof(struct polinom));
	if (q == NULL) {
		printf("Greska!");
		return 0;
	}

	q->koeficjent = koe;
	q->potencija = pot;

	q->Next = p->Next;
	p->Next = q;

	return 0;
}

int ZbrojiPolinome(struct polinom* p, struct polinom* q, struct polinom* suma) {

	while (p->Next != NULL && q->Next != NULL) {

		if (p->Next->potencija == q->Next->potencija) {
			SortiraniUnos(p->Next->koeficjent + q->Next->koeficjent, p->Next->potencija, suma);
			p = p->Next;
			q = q->Next;
		}
		else if (p->Next->potencija > q->Next->potencija) {
			SortiraniUnos(p->Next->koeficjent, p->Next->potencija, suma);
			p = p->Next;
		}
		else{
			SortiraniUnos(q->Next->koeficjent, q->Next->potencija, suma);
			q = q->Next;
		}
	}

	while (p->Next != NULL) {
		SortiraniUnos(p->Next->koeficjent, p->Next->potencija, suma);
		p = p->Next;
	}

	while (q->Next != NULL) {
		SortiraniUnos(q->Next->koeficjent, q->Next->potencija, suma);
		q = q->Next;
	}

	return 0;
}

int PomnoziPolinome(struct polinom* p, struct polinom* q, struct polinom* produkt) {

	while (p->Next != NULL && q->Next != NULL) {

		if (p->Next->potencija == q->Next->potencija) {
			SortiraniUnos(p->Next->koeficjent * q->Next->koeficjent, p->Next->potencija, produkt);
			p = p->Next;
			q = q->Next;
		}
		else if (p->Next->potencija > q->Next->potencija) {
			SortiraniUnos(p->Next->koeficjent, p->Next->potencija, produkt);
			p = p->Next;
		}
		else {
			SortiraniUnos(q->Next->koeficjent, q->Next->potencija, produkt);
			q = q->Next;
		}
	}

	while (p->Next != NULL) {
		SortiraniUnos(p->Next->koeficjent, p->Next->potencija, produkt);
		p = p->Next;
	}

	while (q->Next != NULL) {
		SortiraniUnos(q->Next->koeficjent, q->Next->potencija, produkt);
		q = q->Next;
	}

	return 0;
}
