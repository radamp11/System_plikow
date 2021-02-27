#include "FAT.h"

int main(int argc, char* argv[]) {
	int value;
	int result;
	if(argc < 2)
		return -1;
	value = atoi(argv[1]);
	switch (value) {
		case 0:
			if (createDisc() < 0) { printf("Couldnt create a disc"); return -1; }
		break;
		case 1:
			if(argc != 4) return -1;
			result = copyOnDisc(argv[2], argv[3]);
			if (result == ERROR_NAME_NOT_UNIQUE) {
				printf("File with that name already exist in disc.\n"); 
				return -1;
			}
			if (result == ERROR_NOT_ENOUGH_SPACE) {printf("File is larger than space in disc. Couldnt copy a file.\n");return -1;}
			if(result < 0) {printf("Couldnt copy on disc.\n"); return -1;}
		break;
		case 2:
			if(argc != 4) return -1;
			result = copyFromDisc(argv[2],argv[3]);
			if(result == ERROR_FILE_NOT_FOUND) {printf("File with such name doesnt exist inside disc\n");return -1;}
			if(result < 0) return -1;
		break;
		case 3:
			showInsides();
		break;
		case 4:
			showFolder();
		break;
		case 5:
			resetDisc();
		break;
		case 6:
			deleteDisc();
		break;
		case 7:
			if(argc != 3) return -1;
			result = deleteFile(argv[2]);
			if(result == ERROR_FILE_NOT_FOUND) {printf("File with such name doesnt exist inside disc\n");return -1;}
			if(result < 0) return -1;
		break;
		case 8:
			result = readFile( argv[2] );
			if( result == ERROR_FILE_NOT_FOUND) {printf("File with such name doesnt exist inside disc.\n");return -1;}
			if( result == 1 ) {printf( "\nData has been read correctly.\n");}
		break;
		case 9:
			result = writeToFile( argv[2], argv[3]);
			if( result == 1 ) {printf( "\nData has been written correctly.\n" );}
		break;
		
	}
	return 0;
}
