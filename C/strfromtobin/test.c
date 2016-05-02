
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// Stringify binary data. Output buffer must be twice as big as input,
// because each byte takes 2 bytes in string representation
static void bin2str(char *to, const unsigned char *p, size_t len) {
  static const char *hex = "0123456789abcdef";

  for (; len--; p++) {
    *to++ = hex[p[0] >> 4];
    *to++ = hex[p[0] & 0x0f];
  }
  *to = '\0';
}

unsigned char char2val(const char source)
{
	static const char * hex = "0123456789abcdef";
	size_t index = 0;
	int bLegalChar = 0;

	printf("source char =%c\n", source);

	for ( index=0 ; index < 16; index++ )
	{
		if ( source == *(hex+index)  )
		{
			bLegalChar = 1;
			break;
		}
	}

	if ( !bLegalChar )
	{
		return -1;	
	}


	if ( '0' <= source && source <='9'  )
	{
		return (unsigned char) (source - '0');
	}
	else if ( 'a' <= source && source <= 'f' )
	{
		return (unsigned char) (source - 'a') + 10 ;
	}
	else
	{
		return -1;
	}
}

// translate hex string to dest bin buff, which is len in length
static void str2bin(const char* source, unsigned char * dest, size_t len)
{
	unsigned char byte_total = 0;
	unsigned char byte_pre = 0;
	unsigned char byte_post = 0;
	const char *  hex = 0;
	size_t destIndex = 0;

	if ( strlen(source) % 2 == 1 )
	{
		printf("!! hex string len error!\n");
		return;
	}

	hex = source;
	while ( *(hex) )
	{
		byte_pre = char2val(*hex);
		hex++;

		byte_post = char2val(*hex);
		hex++;

		byte_total = byte_pre << 4 ;
		printf("byte_total pre << 4 = %d\n", byte_total);

		byte_total += byte_post;

		printf("byte_pre=%d\n", byte_pre);
		printf("byte_post=%d\n", byte_post);
		printf("byte_total=%d\n", byte_total);

		if ( destIndex < len )
		{
			*(dest + destIndex) = byte_total;
			destIndex++;
		} 
		else
		{
			break;
		}
	}
}




#define byte unsigned char

#define default_val (unsigned long)-1


void main()
{

	char binstr[1024] = {0};
	char binstr2[1024] = {0};


	printf("aaaa\n");

	byte buff[4] = {0};

	byte buff2[4] = {0};

	memset(buff, -1, 4);

	bin2str(binstr, buff, 4);

	printf("buff binstr =%s\n", binstr );

	str2bin(binstr, buff2, 4);

	bin2str(binstr2, buff2, 4);

	printf("buff2 binstr2 =%s\n", binstr2);

	printf("bbbb\n");
}




