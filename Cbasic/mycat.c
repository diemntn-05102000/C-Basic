#include<stdio.h>
#include<stdlib.h>
#include<string.h>
enum { success, fail };
void main(int argc, char* argv[])
{
	if (argc != 2 && argc != 3)
		exit(1);
	if (argc == 3 && strcmp("-p", argv[2]) != 0)
		exit(1);
	FILE* fp;
	char* buffer;
	int size;
	int result;
	int seek1, seek2 = 0;
	char c;
	int reval = success;
	fp = fopen(argv[1], "r+");
	if (fp == NULL)
	{
		printf("cannot open file %s\n", argv[1]);
		exit(1);
	}
	fseek(fp, 0, SEEK_END);
	size = ftell(fp);
	rewind(fp);
	if (argc == 2)
	{
		buffer = (char*)malloc(sizeof(char) * size);
		if (buffer == NULL) 
		{ 
			fputs("Memory error", stderr);
			exit(2);
		}
		// ch? này fread có buffer r?i 1 là nh? nào ? ._.
		//Answer: 1 là size của 1 block dc đọc, có thể hiểu là đọc size (số lượng ) các block kích cỡ  1 byte.
		result = fread(buffer, 1, size, fp);
		if (result != size)
		{
			fputs("Reading error", stderr);
			exit(3);
		}
		printf("%s", buffer);
	}
	else
	{
		do
		{
			int n = 0;
			do
			{
				c = fgetc(fp);
				n += 1;
				if (feof(fp))
				{
					buffer = (char*)malloc(sizeof(char) * (size - seek2 + 1));
					if (buffer == NULL)
						//stder: hien? thi khi bao loi~ nguon`: mang.
					{
						fputs("Memory error", stderr);
						exit(2);
					}
					fseek(fp, seek2, SEEK_SET);
					result = fread(buffer, 1, size - seek2, fp);
					printf("%s\n", buffer);
					//exit(0) và exit 1 khác nhau nh? nào ? ._. theo nh? em hi?u thì exit(0) thì nó in t? ?ây lên trên
					//bên d??i ch? có gì n?a ._. right??
					//Answer: Đoạn này viết exit cho chuyen nghiệp thôi chứ dùng return cũng dc rồi, nếu dịch = gcc và chạy
					// bằng CLI thì ko khác return mấy.
					exit(0);
				}
			} while ((c != '\n' && c != '\0') || n <= 256);
			seek1 = seek2;
			//ch? này l?y v? trí tr? c?a fp gán vào  seek2 ?úng k ta??
			// Answer: cái này là để luân phiên đổi giữa 2 con trỏ để đánh dấu giới hạn trên và giới hạn dưới 
			//của đoạn văn bản cần sao chép thôi
			seek2 = ftell(fp);
			if (seek2 == EOF) printf("bug");
			buffer = (char*)malloc(sizeof(char) * (seek2 - seek1 + 1));
			if (buffer == NULL)
			{
				fputs("Memory error", stderr);
				exit(2);
			}
			fseek(fp, seek1, SEEK_SET);
			//lúc seek2-seek1 lúc thì size- là sao ? ._.
			// seek 2 - seek1 là vì lúc đấy chưa gặp EOF thì đánh dấu dc giới hạn trên dưới, gặp
			//EOF thì cái seek2 đọc bị lỗi nên phải lấy size - đi
			result = fread(buffer, 1, seek2 - seek1, fp);
			printf("%s\n", buffer);
			printf("Press enter to continue...\n");
			getchar();
		} while (1);
		//while 1 là sao ? ._.
		// là luôn đúng, tức là vòng lặp vô hạn
	}

	return;
}
