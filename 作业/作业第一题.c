#include <stdio.h>
#include <stdlib.h>


int get_string_length(char* str)
{
	int length = 0;
	char * p = str;
	while (*p++)
	{
		length++;
	}
	return length;
}


char * my_strstr(const char* heystack, const char* needle)
{
	char* p = heystack;
	char* q = needle;
	int len = get_string_length(needle);
	int len_heystack = get_string_length(heystack);
	int compared_length = 1;
	//printf("Here is inside my_strstr and the length of needle is %d \n", len);

	while (*p++)
	{
		len_heystack--;
		if (len_heystack < len-1)
		{
			//printf("string not found!\n");
			return NULL;
		}
		if (*(p) == *(q))
		{
			for (int i = 1; i < len; i++)
			{
				if(*(p + i) == *(q + i))
				{
					//printf("No. %d character is same %c \n",i, *(p+i));
					compared_length++;
				}
				else
				{
					break;
				}
			}
			if (compared_length == len)
			{
				//printf("found \n");
				return p;
			}
		}
	}

}


int main()
{
	char* str = "this is heysyack,and here is a needle inside";
	char* test_str = "12345";
	printf("%d\n", get_string_length(test_str));
	char* needle = "needle";

	char* p = my_strstr(str, needle);
	printf("%s\n", p);

	return 0;
}