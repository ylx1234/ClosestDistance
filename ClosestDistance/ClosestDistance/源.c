#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define min(x,y) (x<y)?x:y
#define MAX 100
typedef struct coordinate {
	int x, y;
}point;
point z[MAX];
double distance(point z1, point z2)
{
	double t;
	t = (z1.x - z2.x)*(z1.x - z2.x) + (z1.y - z2.y)*(z1.y - z2.y);
	return sqrt(t);
}

double Divide(point s[], int left, int right) {
	if (right - left == 1) {
		return distance(s[right], s[left]);
	}
	if (right - left == 2) {
		double d1 = distance(s[right], s[left]);
		double d2 = distance(s[right], s[left + 1]);
		double d3 = distance(s[left + 1], s[left]);
		d2 = min(d1, d2);
		d3 = min(d2, d3);
		return d3;
	}
	int m = (right + left) / 2;
	int i, j;
	double d1 = Divide(s, left, m);
	double d2 = Divide(s, m + 1, right);
	double d = min(d1, d2);
	int l = left, r = right;
	while (s[l].x < s[m].x - d && l <= right);
	l++;
	while (s[r].x > s[m].x + d && r >= left)
	r--;
	double d3;
	for (i = l; i <= r; i++) {
		for (j = i + 1; j <= r; j++) {
			if (s[j].y - s[i].y >= d) {
				break;
			}
			else {
				d3 = distance(s[i], s[j]);
				if (d3 < d)
					d = d3;
			}
		}
	}
	return d;
}

int main()
{
	int i, j;
	int n = rand() % 10 + 10;
	printf("随机生成的点数为: %d\n", n);
		for (i = 0; i < n; i++) {
		z[i].x = rand() % 100;
		z[i].y = rand() % 100;
		for (j = 0; j < i; j++) {
			if (z[j].x == z[i].x&&z[j].y == z[i].y) {
				i--;
				break;
			}
		}
	}
	for (i = 0; i < n; i++) {
		printf("(%d,%d)", z[i].x, z[i].y);
	}
	printf("\n最近点对最小距离为 %lf\n",Divide(z, 0, n - 1));
	return 0;
}