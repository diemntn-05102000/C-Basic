#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"prefix.h"

int n;// số từ trong câu

void read ( char *str ) { // đọc dữ liệu từ bàn phím
	strcpy(str,"");// chuỗi ban đầu trống

	printf("Xac nhan ket thuc van ban bang cach go: E + Enter.\n");

	char ctt[50];
	
	while(1) {

		gets(ctt);
		
		if ( strcmp( ctt, "e") == 0 || strcmp( ctt, "E") == 0 ) {
			str[strlen(str)-1] = '\0';// do sau khi kết thúc 1 dòng thì luôn thên 1 dấu cách vào sau cùng của str
			break; // kết thúc văn bản
		} else {
			strcat(str, ctt);
			strcat(str, "\n");// ký tự đặc biệt
		}
	}
}

char **divideWord ( char *str ) { // chia văn bản thành các từ
	char *q = strtok(str," \n");// hàm tách chuỗi bằng ký tự cách và enter, hàm này ko xử lý các ký tự cách ở cuối
	char **p = (char**)malloc(sizeof(char)*100);
	n = 0;// số tự ban đầu bằng 0

	while ( q != NULL ) {
		p[n] = q;
		q = strtok(NULL," \n");
		n++;
	}
	
	return p;
}

void stand ( char *str ) { // chuẩn hóa xâu
	char *v = NULL;
	v = (char*)malloc(sizeof(char)*100);
	strcpy(v,"");
	char **e = divideWord(str);

	for ( int i = 0; i < n; i++ ) {
		strcat(v,e[i]);
		strcat(v," ");
	}

	strcpy(str,v);// xong việc thì trả lại cho str
	free(v);
	free(e);
	
	for (int i = strlen(str) - 1; i >= 0; i-- ) {
		if ( str[i] != ' ' ) {
			str[i+1] = '\0';
			break;
		}
	}
}

int checkName ( char *word) { // kiểm tra tên riêng
	if ( strlen(word) > 3 ) {
		if ( word[0] >= 'A' && word[0] <= 'Z' ) { // chữ cái đầu phải viết hoa, số ký tự phải lớn hơn 3
			return 1;
		}
		return 0;
	}
	return 0;
}

int countName ( char *str ) { // đếm tên
	char **e = divideWord(str);
	int count = 0;

	for ( int i = 0; i < n; i++ ) {
		if ( checkName ( e[i] ) == 1 ) {
			count++;
		}
	}
	free(e);

	return count;
}

int find ( char *str, char *s ) {// tìm vị trí đầu tiên s xuất hiện trong str
	char *m = strstr(str,s);

	return strlen(str) - strlen(m);// nếu trả về n tức là ko có s trong str
}

void replace ( char *str, char *s1, char *s2 ) {// hàm thay s1 thành s2
	
	int t = find(str, s1); //vị trí xuất hiện đầu tiên của s1 trong str

	if ( t != n ) { // nếu t == n tức là ko tồn tại s1 trong str nên ko thay

		char *y;
		y = (char*)malloc(sizeof(char)*100);
		strcpy(y,"");

		for ( int i = 0; i < t; i++ ) {// coppy từ đầu đến s1
			y[i] = str[i];
		}

		strcat(y,s2); //nối s2 vào y
		int z = strlen(y);

		for ( int i = 0; i <= strlen(strstr(str,s1)) - strlen(s1) + strlen(s2); i++ ) {
			y[i+z] = str[ t + strlen(s1) + i];
		}

		// sau tất cả, coppy trả lại str
		strcpy(str, y);
		free(y);
	}	
}

struct WORD { // khai báo struct word
	char w[100];
	int f;
};
typedef struct WORD word;

void outFreq ( word k[], int n ) { // in ra các phần tử và tần số của các từ trong k
	for ( int i = 0; i < n; i++) {
		printf("\n%s: %d", k[i].w, k[i].f);
	}
}

int checkExist ( word k[], int n, char *str ) { // kiểm tra str đã có trong k hay chưa
	for ( int i = 0; i < n; i++ ) {
		if ( strcmp(k[i].w, str ) == 0 ) return i;// nếu có thì trả về vị trí của nó trong k
	}

	return 0;// không có thì trả về không
}

void freq ( char *str ) {// xử lý và in ra tần số của các từ trong chuỗi nhập vào
	char **e = divideWord(str);// sau khi divideWord chạy xong thì mới có n
	word k[n]; // mảng có số phần tử là số từ trong văn bản
	
	for ( int i = 0; i < n; i++ ) {// khởi tạo
		strcpy( k[i].w, "");
		k[i].f = 0;
	}

	int t = 0; // số phần tử ban đầu của k
	for ( int i = 0; i < n; i++ ) { // duyệt lần lượt các từ
		
		int a = checkExist( k, n, e[i]);// kiểm tra xem s[i] tồn tại trong k chưa
		
		if ( a != 0 ) {// nếu có rồi thì tăng tần số của từ đó lên 1
			k[a].f++;
		} else {// nếu chưa thì tạo mới
			strcpy(k[t].w, e[i]);
			k[t].f++;
			t++;
		}
	}

	outFreq(k,t);
	free(e);
}

void space ( char *str ) { // biến các ký tự dấu câu thành dấu cách
	for ( int i = 0; i < strlen(str); i++ ) {
		if ( str[i] == ',' || str[i] == '.' || str[i] == '?' || str[i] == '!' || str[i] == '\'' || str[i] == ':' ) {
			str[i] = ' ';
		}
	}
}

void checkKey ( char *str ) {

	FILE *f = fopen("english3.txt","r");// mở file
	

	if ( f == NULL ){
		printf("\nFILE NOT FOUND.!!!");
	}
	else {

		
		node head = newNode();

		while ( !feof(f) ) {
			char s[50]; // khai báo mảng ký tự s
			fscanf(f,"%s",s);// đọc s trong file
			insert (head, strlwr(s)); // thêm s vào cây
		}
		
		space(str);
		stand(str);
		char **e = divideWord(str);// tách từ

		for ( int i = 0; i < n; i++ ) {
			
			if ( checkName( e[i] ) == 0 ) {
				if ( isExist ( head, strlwr(e[i]) ) == 0 ) {
					puts(e[i]);
				}
			}
		}
	
		clear(head);
		free(e);
	}

	

	fclose(f);// đóng file
}

int main(){
	char *s;
	s = (char*)malloc(sizeof(char)*100);
	read(s);
	// char s[] = "I am a studentbhjtrcf, Mganga";
	stand(s);
	puts(s);

	//checkKey(s);
	// freq(s);
	// replace(s,"ng","");
	// puts(s);
	// printf("%d",strlen(s));
	// printf("\nTen rieng: %d",countName(s));
	// printf("%d",countWord(s));
	// free(s);
}