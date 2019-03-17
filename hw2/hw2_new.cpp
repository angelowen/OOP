#include <bits/stdc++.h>
#define len 20
using namespace std;
int q[1024];
int dot = 0, graph[len][len];
typedef struct node {
		int val;
		struct node *lu;   //左上
		struct node *ru;   //右上
		struct node *eld;  //左下
		struct node *rd;   //右下
		struct node *pre;
} Node;
void cut(char *arr[], int dir, int row_st, int row_end, int col_st,
				int col_end);
void finding_root(Node *cur, int base) {
		int sum = base;
		while (cur->pre != NULL) {
				sum = (cur->val) + sum * 5;
				cur = cur->pre;
		}
		q[dot] = sum;
	}
int check(Node *cur, char arr[][len], int row_st, int row_end, int col_st,
				int col_end, int base) {
		int i, j;
		char tmp = arr[row_st][col_st];
				for (i = row_st; i < row_end; i++) {
				for (j = col_st; j < col_end; j++) {
						if (arr[i][j] != tmp) {
								return 0;
						}
				}
		}

		if (tmp == '1') {
				
				finding_root(cur, base);
							dot++;
				return 1;  // all black
		} else {
							return 2;  // all white
		}
}
void do_cut(Node *root, char arr[][len], int row_st, int row_end, int col_st,
				int col_end) {
		int half = (row_end - row_st) / 2;
		if (!check(root, arr, row_st, row_st + half, col_st, col_st + half, 1)) {
				Node *cur = (Node *)malloc(sizeof(Node));
				cur->val = 1;
				root->lu = cur;
				cur->pre = root;
				do_cut(cur, arr, row_st, row_st + half, col_st, col_st + half);
		}
		if (!check(root, arr, row_st, row_st + half, col_st + half, col_end, 2)) {
				Node *cur = (Node *)malloc(sizeof(Node));
				cur->val = 2;
				root->ru = cur;
				cur->pre = root;
				do_cut(cur, arr, row_st, row_st + half, col_st + half, col_end);
		}
		if (!check(root, arr, row_st + half, row_end, col_st, col_st + half, 3)) {
				Node *cur = (Node *)malloc(sizeof(Node));
				cur->val = 3;
				root->eld = cur;
				cur->pre = root;
				do_cut(cur, arr, row_st + half, row_end, col_st, col_st + half);
		}
		if (!check(root, arr, row_st + half, row_end, col_st + half, col_end, 4)) {
				Node *cur = (Node *)malloc(sizeof(Node));
				cur->val = 4;
				root->rd = cur;
				cur->pre = root;
				do_cut(cur, arr, row_st + half, row_end, col_st + half, col_end);
		}
}
int check_all_black(int n,char arr[][len]){
	int i,j;
		for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					if(arr[i][j]=='0')
							return 0;
				}
		}
		return 1;
}
void type1(int num, int image) {
		char arr[len][len], i, j;
		char c;
		dot = 0;
		for (j = 0; j < num; j++) {
				cin >> arr[j];
		}
		if( check_all_black(num,arr)){
			cout<<"0"<<endl;
			cout << "Total number of black nodes = 1"<< '\n' << '\n';
			return ;
		}
		Node *root;
		root->pre = NULL;
		do_cut(root, arr, 0, num, 0, num);
		sort(q, q + dot);
		for (i = 0; i < dot; i++) {
				cout << q[i] << " ";
		}
		if (dot) cout << endl;
		cout << "Total number of black nodes = " << dot << '\n' << '\n';
}
int trans(int num) {
		int q, r, cnt = 0, sum = 0;
		while (num / 5 > 0) {
							r = num % 5;
				num /= 5;
				sum += r * pow(10, cnt);
				cnt++;
		}
		sum += num * pow(10, cnt);
		return sum;
}
void filled(int row_st, int row_end, int col_st, int col_end) {
		int i, j;
		for (i = row_st; i < row_end; i++) {
				for (j = col_st; j < col_end; j++) {
						graph[i][j] = 1;
				}
		}
}
void finding(int *d, int half, int row_st, int row_end, int col_st,
				int col_end) {
		int i, j, num;
		num = (*d) % 10;
		(*d) = (*d) / 10;
		if (num == 1) {
				finding(d, half / 2, row_st, row_st + half, col_st, col_st + half);
		} else if (num == 2) {
				finding(d, half / 2, row_st, row_st + half, col_st + half, col_end);
		} else if (num == 3) {
				finding(d, half / 2, row_st + half, row_end, col_st, col_st + half);
		} else if (num == 4) {
				finding(d, half / 2, row_st + half, row_end, col_st + half, col_end);
		}
		if (num == 0) {
				filled(row_st, row_end, col_st, col_end);
				return;
		}
}
void Print(int row) {
		for (int i = 0; i < row; i++) {
				for (int j = 0; j < row; j++) {
						if (graph[i][j])
								cout << '*';
						else
								cout << '.';
				}
				cout << endl;
		}
}
void type2(int num, int image) {
		int arr[100];
		int i, j, cnt = 0, d;
		int half = (0 - num) / 2;
		num = 0 - num;
			memset(graph, 0, sizeof(graph));
		while (cin >> arr[cnt] && arr[cnt] != -1) {
				cnt++;
		}
		for (i = 0; i < cnt; i++) {
				d = trans(arr[i]);
				finding(&d, half, 0, num, 0, num);  // num=row&col
		}
		Print(num);
}
int main(int argc ,char *argv[]) {
		int i, j, num,image=0;
		num=atoi(argv[1]);
		if (num > 0) {
				type1(num, image);
		} else {
				type2(num, image);
		}
		return 0;
}
