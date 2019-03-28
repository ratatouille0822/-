#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int getKeyByValue(char *keyvaluebuf, char *keybuf, char *valuebuf, int * valuebuflen);
int removeBlankFromHeadAndRear(char** str);


int main(void)
{
	char buf[128] = { 0 };
	int len = 0;

	/* 在"key1 =    valude1"中查找"key1"匹配的字符串，
	   如果找到，获取=后面的字符串，而且去掉多余空格
	*/
	int ret = getKeyByValue("key1 =    valude1   ", "key1", buf, &len);
	//调用函数后：buf="valude1", len=7
	printf("-->%s<--%d__%d", buf, len, ret);

	return 0;
}

int getKeyByValue(const char *keyvaluebuf,const char *keybuf, char *valuebuf, int * valuebuflen)
{
	int key_length_gross = 0, value_length_gross = 0, key_length_net = 0, value_length_net = 0;
	char* p_equal = keyvaluebuf;

	while (*(p_equal++) != '=')
	{
		key_length_gross++;
	}

	char* tmp = p_equal;

	while (*p_equal++)
	{
		value_length_gross++;
	}
	//printf("%d--%d--\n", key_length_gross, value_length_gross);

	char* key = (char*)malloc(key_length_gross+1);
	char* value = (char*)malloc(value_length_gross+1);

	memcpy(key, keyvaluebuf, key_length_gross);
	memcpy(value, tmp, value_length_gross);

	key[key_length_gross] = 0;
	value[value_length_gross] = 0;

	//printf("--->%s<---\n", key);
	//printf("--->%s<---\n", value);

	key_length_net = removeBlankFromHeadAndRear(&key);
	value_length_net = removeBlankFromHeadAndRear(&value);

	//printf("%d__%d__\n",key_length_net,value_length_net);
	//printf("--->%s<---\n--->%s<---\n", key, value);

	
	strcpy(valuebuf, value);
	*valuebuflen = value_length_net;

	free(key);
	free(value);

	if (strcmp(key, keybuf) == 0)
		return 0;
	else
		return -1;
}


int removeBlankFromHeadAndRear(char** str)
{
	unsigned int len = strlen(*str);
	char* head = *str;
	char* rear = *str + len -1;
	while (head < rear)
	{
		if (*head == ' ')
			head++;
		else if (*rear == ' ')
			rear--;
		else
			break;
	}
	int length_net = rear - head;
	head[length_net+1] = 0;
	//printf("--->inside remove length net %d\n",length_net+1);
	strcpy(*str, head);
	return length_net + 1;
}





















