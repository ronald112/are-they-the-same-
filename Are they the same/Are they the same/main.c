#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

/*If a or b are nil(or null or None), the problem doesn't make sense so return false.
	If a or b are empty then the result is self - evident. (a[i] == 0) ||   */

bool comp(const int *a, const int *b, size_t n)
{
	bool *arr = (bool *)malloc(n * sizeof(bool));
	for (int i = 0; i < n; i++) arr[i] = false;

	if ((b == NULL) || (a == NULL)) {
		free(arr);
		return false;
	}

	bool flag = 0;
	for (int i = 0; i < n; i++) {
		if ((a[i] == 0) && (a[i] == b[i]))  flag = 1;
		else {
			flag = 0;
			break;
		}
	}
	if (flag == 1) {
		free(arr);
		return true;
	}

	flag = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((a[i] == 0) || ((a[j] * a[j]) != b[i]))
				flag = 0;
			else {
				if (arr[j] != true) {
					arr[j] = true;
					flag = 1;
					break;
				}
			}
		}
		if (flag == 0) {
			free(arr);
			return false;
		}
	}
	free(arr);
	return true;
}


int main() {
	int a[] = { 2, 2, 3 };
	int b[] = { 4, 9, 9 };

	/*int a[] = { 2, 2, 3 };
	int b[] = { 4, 4, 9 };*/

	/*int a[] = { 4, 9, 14, 7, 6, 6, 11, 7, 8 };
	int b[] = { 49, 81, 121, 36, 16, 196, 36, 64, 49 };*/

	bool result = comp(a, b, 3);

	if (result) {
		printf("true %lu\n", 9%2);
	}
	else {
		printf("false\n");
	}
	
	system("pause");
	return 0;
}
