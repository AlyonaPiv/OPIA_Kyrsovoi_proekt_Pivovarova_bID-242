#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int** zap_sobstv(int** A, int s1, int k1);						// ������� ��� ������������ ���������� �������
int** random(int** A, int d, int s1, int k1);					// ������� ��� ���������� ������� � ������� ���������� ��������� �����
int** proizvedenie(int** A, int** B, int s1, int k1, int k2);	// ������� ������������ ������
void print(int** A, int s1, int k1);							// ������� ������ ������
int** sort_rascheska(int** C, int s3, int k3);					// ���������� ��������� �� ����������� ��������� ��������� �������

int main() {
	setlocale(LC_ALL, "RUS");

	puts("\t****************************************************************************************");
	puts("\t*                                 �������� ������                                      *");
	puts("\t*                                                                                      *");
	puts("\t*                        ���������� ������� ������: ���-242                            *");
	puts("\t*                           ���������� ���� �����������                               *");
	puts("\t*                                                                                      *");
	puts("\t*                       �������: ���� ��� ��������� �������                            *");
	puts("\t*          ����������� �� ��� �������. ��������� �������� � ������ ������.             *");
	puts("\t*                 ������������ ������ ������������� ������� ��������                   *");
	puts("\t*              (���������� ��������� ������� ��������� �� �����������)                 *");
	puts("\t****************************************************************************************");

	while (1) { // ����������� ���� � ������������ ������
		char o;

		puts("\n\t     ����� �������� ���� ��������� ���������, ���������� ������ ���������� ������: \n\t    ���������� ����� ������ ������� ������ ��������� � ����������� �������� ������.\n\t\t\t\t\t  ������ �����������!");

		int s1, s2, k1, k2; /* s1, s2 - ���������� ����� � ��������; k1, k2 - ���������� �������� � ��������.*/
		printf("\n\t������� ���������� ����� ������ �������:  ");
		scanf_s("%d", &s1);
		printf("\n\t������� ���������� �������� ������ �������:  ");
		scanf_s("%d", &k1);

		printf("\n\t������� ���������� ����� ������ �������:  ");
		scanf_s("%d", &s2);
		printf("\n\t������� ���������� �������� ������ �������:  ");
		scanf_s("%d", &k2);

		int** A = (int**)malloc(s1 * sizeof(int*));		/* ��������� ������ ��� ������ ������ */
		for (int i = 0; i < s1; i++) {
			A[i] = (int*)malloc(k1 * sizeof(int));
		}
		if (A == NULL) {
			puts("����������� ���������");
			return -1;
		}

		int** B = (int**)malloc(s2 * sizeof(int*));
		for (int i = 0; i < s2; i++) {
			B[i] = (int*)malloc(k2 * sizeof(int));
		}
		if (B == NULL) {
			puts("����������� ���������");
			return -1;
		}

		if (k1 != s2) {	/*�������� ���������� ������� ��������� ������ */
			printf("\n\n\t   ���������� �������� ������ ������� �� ��������� � ����������� ����� ������ �������: \n\t\t\t\t         ��������� ����������\n\n");
			for (int i = 0; i < s1; i++) {	// ������������ ������, ���� ������� ������ �����������
				free(A[i]);
			}
			free(A);
			for (int i = 0; i < s2; i++) {
				free(B[i]);
			}
			free(B);
			continue;
		}
		else {
			printf("\n\t\t��������� ��������! \n\n");
		}

		int spsb, end, d; /*spsb - ������ ����������, end - ������ ������, d - �������� ��� ��������� ��������� �����.*/
		printf("\n\t�������� ������ ������������� ��������: \n\t\t 1 - ���������������; \n\t\t 2 - � ������� ��������� ��������� �����\n\t\t\t");
		scanf_s("%d", &spsb);
		printf("\n\t�������� ������ ������ ����������: \n\t\t 1 - ������ �����, ������������ � ���������� ��������� ������; \n\t\t 2 - ��� ��� �������;\n\t\t\t");
		scanf_s("%d", &end);

		switch (spsb) {	/* ������������� �� ������ ������������ */
		case 1:
			printf("\n\t\t������� ������ �������:   \n");
			zap_sobstv(A, s1, k1);
			printf("\n");

			printf("\n\t������� ������ �������:   \n");
			zap_sobstv(B, s2, k2);
			printf("\n");
			break;

		case 2:
			printf("\n\t������� ������������ �������� ��������� > 1\n\t(��������, �� ������� '10' - �������� ����� �� -10 �� 10):\t  ");
			scanf_s("%d", &d);

			random(A, d, s1, k1);
			random(B, d, s2, k2);
			break;
		default:
			printf("��������� ����������� ���������, ���������� ��� ���!");
			break;
		}

		int** C = proizvedenie(A, B, s1, k1, k2); /*������� ������������ ������*/

		switch (end) {	/*����� ����������� �� ������ ������������*/
		case 1:
			printf("\n\t\t��������� ���������: \n\n");
			print(C, s1, k2);

			break;
		case 2:
			printf("\n\t\t������ �������: \n\n");
			print(A, s1, k1);

			printf("\n");

			printf("\n\t\t������ �������: \n\n");
			print(B, s2, k2);

			printf("\n");

			printf("\n\t\t��������� ���������: \n\n");
			print(C, s1, k2);

			break;
		default:
			printf("��������� ����������� ���������, ���������� ��� ���!");
			break;
		}

		printf("\n\t\t��������������� ������: \n\n");
		sort_rascheska(C, s1, k2);
		print(C, s1, k2);

		for (int i = 0; i < s1; i++) {		/* ������������ ������ */
			free(A[i]);
		}
		free(A);
		for (int i = 0; i < s2; i++) {
			free(B[i]);
		}
		free(B);
		for (int i = 0; i < s1; i++) {
			free(C[i]);
		}
		free(C);

		printf("\n");
		printf("���������� ? (�� - 'y', ��� - 'n')  ");
		scanf_s("%c", &o);
		o = getchar();
		if (o == 'y') {
			continue;
		}
		else if (o == 'n') {
			break;
		}
		else {
			printf("������\n");
			break;
		}
		printf("\n");
	}
}

int** zap_sobstv(int** A, int s1, int k1) {
	for (int i = 0; i < s1; i++) {			// ������� ������������� ��� ����, ����� 
		for (int j = 0; j < k1; j++) {		// ������������ ��� �������������� ����������������
			printf(" a[%d][%d] = ", i, j);	// �������� ������� � �������
			scanf_s("\n%d", &A[i][j]);
		}
	}
	return A;
}

int** random(int** A, int d, int s1, int k1) {
	for (int i = 0; i < s1; i++) {					// ������� ������������� ��� ����, �����
		for (int j = 0; j < k1; j++) {				// ������ ����������������� ����������
			A[i][j] = -d + rand() % (d - (-d));		// ���������������� �������
		}
	}
	return A;
}

int** proizvedenie(int** A, int** B, int s1, int k1, int k2) {

	int s3 = s1; /* ��� - �� ����� � ����� ������� = ��� - �� ����� ������ ������� */
	int k3 = k2; /* ��� - �� �������� � ����� ������� = ��� - �� �������� ������ ������� */

	int** C = (int**)malloc(s3 * sizeof(int*));		// ������� ������������� ��� ����, �����
	for (int i = 0; i < s1; i++) {					// ����������� ������� (�������) � ���������� ��������� � ����� ������
		C[i] = (int*)malloc(k3 * sizeof(int));
		if (C[i] == NULL) {
			return NULL;
		}
	}

	for (int i = 0; i < s3; i++) {
		for (int j = 0; j < k3; j++) {
			C[i][j] = 0;
			for (int k = 0; k < k1; k++) {
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	return C;
}

void print(int** A, int s1, int k1) {
	for (int i = 0; i < s1; i++) {			// ������� ������������� ��� ����, �����
		for (int j = 0; j < k1; j++) {		// ������ ��������� �� ����� 

			printf(" %3d ", A[i][j]);
		}
		printf("\n");
	}
}

int** sort_rascheska(int** C, int s3, int k3) {
	int size_d;			 // ���������� ��������� �� ������� ���������  
	if (s3 < k3) {		 // ������������ ������� ���������� �������
		size_d = s3;	 // (����������� ����� ��� ��������)
	}
	else {
		size_d = k3;
	}

	int* d = (int*)malloc(size_d * sizeof(int));
	if (d == NULL) {   	/* ������, � ������� ����� ��������� �������� ������� ���������*/
		return;
	}
	for (int i = 0; i < size_d; i++) {
		d[i] = C[i][i];
	}
	int s = size_d;		 /* ��������� ��� */
	int c;				 /* ������� ������������ */
	while (s > 1) {
		s = s * 10 / 13; /* ��� ��� ������ ������� */
		if (s < 1) {
			s = 1;
		}
		c = 0;
		for (int i = 0; i < size_d - s; i++) {
			if (d[i] > d[i + s]) {
				int t = d[i];
				d[i] = d[i + s];
				d[i + s] = t;
				c++;
			}
		}
		if (c = 0 && s == 1) {
			break;		/* ���������, ���� ��� ������������ � ��� s == 1 */
		}
	}
	for (int i = 0; i < size_d; i++) {
		C[i][i] = d[i]; /* �������� �������� ��������� � �������� ������� */
	}
	free(d);			/* ����������� ������ ����� ������������� */

	return C;
}