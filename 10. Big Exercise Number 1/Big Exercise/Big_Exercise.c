/*
* File: Big_Exercise.c
* Author: Võ Thành Danh
* Date: 18/07/2024
* Description:  This is the main source file for my big exercise number 1.\
				The topic is "Managing Apartment Resident Information".
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define CSV_WRITE_FORMAT "%s,%s,%s,%s\n"
#define CSV_READ_FORMAT " %[^,],%[^,],%[^,],%[^\n]"
#define MEMBER_INFORMATION "uID,Room Number,Name,License Plate"
#define MEMBER_PRINTF(member) member.uid,        \
							  member.roomNumber, \
							  member.name,       \
							  member.licensePlate
#define PRINT_MENU_ITEM(number, item) printf("%d. %s\n", number, item)
#define PRINT_MENU(...)                           \
	do                                            \
	{                                             \
		const char *items[] = {__VA_ARGS__};      \
		int n = sizeof(items) / sizeof(items[0]); \
		for (int i = 0; i < n; i++)               \
		{                                         \
			PRINT_MENU_ITEM(i + 1, items[i]);     \
		}                                         \
	} while (0)
#define CASE_OPTION(number, function) \
	case number:                      \
		function(filename);           \
		break;
#define HANDLE_OPTION(option, filename, ...) \
	switch (option)                          \
	{                                        \
		__VA_ARGS__                          \
	default:                                 \
		printf("Invalid option!\n");         \
	}

typedef struct
{
	char uid[20];		   // UID của RFID
	char roomNumber[10];   // Số Phòng
	char name[50];		   // Tên
	char licensePlate[20]; // Biển Số Xe
} Member;

typedef int (*SearchFunction)(const Member *, const char *);

int countMemberUsingCSV(const char *filename)
{
	int count = 0;
	char buffer[sizeof(Member) + 1];
	FILE *fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("Stupid can't open the file\n");
		exit(1);
	}
	if (fgets(buffer, sizeof(buffer), fp) != NULL)
	{
		while (fgets(buffer, sizeof(Member) + 1, fp) != NULL)
		{
			count++;
		}
	}
	else
	{
		printf("Can't fcking read\n");
		exit(1);
	}
	if (fclose(fp) == 0)
	{
		return count;
	}
	else
	{
		printf("Oh no\n");
		exit(1);
	}
}

int countMemberInArray(const Member *member)
{
	int count = 0;
	while (member[count].uid[0] != '\0')
	{
		count++;
	}
	return count;
}

Member *convertCSVtoArray(const char *filename, int memberCount)
{
	Member *member = (Member *)malloc((memberCount + 1) * sizeof(Member));
	if (member == NULL)
	{
		printf("Memory allocation failed for member.\n");
		exit(1);
	}
	else
	{
		char buffer[sizeof(Member) + 1];
		FILE *fp = fopen(filename, "r");
		fgets(buffer, sizeof(buffer), fp); // First line
		for (int i = 0; i < memberCount; i++)
		{
			fscanf(fp, CSV_READ_FORMAT, MEMBER_PRINTF(member[i]));
			fgetc(fp);
		}
		if (fclose(fp) != 0)
		{
			printf("Can't close the file\n");
			exit(1);
		}
		member[memberCount].uid[0] = '\0';
	}
	return member;
}

int compareString(const char *str1, const char *str2)
{
	int i = 0;
	while (str1[i] != '\0' && (str1[i] == str2[i]))
	{
		i++;
	}
	return str1[i] - str2[i];
}

void copyString(char *dest, const char *src)
{
	int i = 0;
	for (i; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
}

void swapString(char *str1, char *str2)
{
	int length = 0;
	while (str1[length] != '\0')
	{
		length++;
	}
	char *temp = (char *)malloc((length + 1) * sizeof(char));
	if (temp == NULL)
	{
		printf("Can't allocate memory for temp\n");
		free(temp);
		exit(1);
	}
	copyString(temp, str1);
	copyString(str1, str2);
	copyString(str2, temp);
	free(temp);
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubbleSort(char **infoArray, int *originalIndex, int memberCount)
{
	for (int i = 0; i < memberCount - 1; i++)
	{
		for (int j = 0; j < memberCount - i - 1; j++)
		{
			if (compareString(infoArray[j], infoArray[j + 1]) > 0)
			{
				swapString(infoArray[j], infoArray[j + 1]);
				swap(&(originalIndex[j]), &(originalIndex[j + 1]));
			}
		}
	}
}

int binarySearch(char **infoArray, int l, int r, const char *info)
{
	if (r >= l)
	{
		int mid = (r + l) / 2;
		if (compareString(infoArray[mid], info) == 0)
		{
			return mid;
		}
		if (compareString(infoArray[mid], info) > 0)
		{
			return binarySearch(infoArray, l, mid - 1, info);
		}
		return binarySearch(infoArray, mid + 1, r, info);
	}
	return -1;
}

void insert1CSVLine(FILE *fp, Member member)
{
	fprintf(fp, CSV_WRITE_FORMAT, MEMBER_PRINTF(member));
	fclose(fp);
}

void delete1CSVLine(const char *filename, int line)
{
	char buffer[sizeof(Member) + 1];
	FILE *fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("Could not open file: %s\n", filename);
		exit(1);
	}
	FILE *fd = fopen("Temp.csv", "w");
	if (fd == NULL)
	{
		printf("Could not open temp file\n");
		fclose(fp);
		exit(1);
	}
	// Read and write each line except the one to be deleted
	int currentLine = 0;
	while (fgets(buffer, sizeof(buffer), fp) != NULL)
	{
		currentLine++;
		if (currentLine != line)
		{
			fputs(buffer, fd);
		}
	}
	fclose(fp);
	fclose(fd);
	if (remove(filename) != 0)
	{
		printf("Can't delete file\n");
		exit(1);
	}
	else
	{
		if (rename("Temp.csv", filename) != 0)
		{
			printf("Can't rename file\n");
			exit(1);
		}
	}
}

void modify1CSVLine(const char *filename, int line, Member updatedMember)
{
	char buffer[sizeof(Member) + 1];
	FILE *fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("Could not open file: %s\n", filename);
		exit(1);
	}
	FILE *fd = fopen("Temp.csv", "w");
	if (fd == NULL)
	{
		printf("Could not open temp file\n");
		fclose(fp);
		exit(1);
	}
	int currentLine = 0;
	while (fgets(buffer, sizeof(buffer), fp) != NULL)
	{
		currentLine++;
		if (currentLine != line)
		{
			fputs(buffer, fd);
		}
		else
		{
			fprintf(fd, CSV_WRITE_FORMAT, MEMBER_PRINTF(updatedMember));
		}
	}
	fclose(fp);
	fclose(fd);
	if (remove(filename) != 0)
	{
		printf("Can't delete file\n");
		exit(1);
	}
	else
	{
		if (rename("Temp.csv", filename) != 0)
		{
			printf("Can't rename file\n");
			exit(1);
		}
	}
}

int searchByUID(const Member *member, const char *uid)
{
	int memberCount = countMemberInArray(member);
	char **uidArray = (char **)malloc(memberCount * sizeof(char *));
	if (uidArray == NULL)
	{
		printf("Memory allocation failed for uidArray.\n");
		exit(1);
	}
	int *originalIndex = (int *)malloc(memberCount * sizeof(int));
	if (originalIndex == NULL)
	{
		printf("Memory allocation failed for originalIndex.\n");
		free(uidArray);
		exit(1);
	}
	for (int i = 0; i < memberCount; i++)
	{
		uidArray[i] = (char *)malloc((sizeof(member[i].uid) + 1) * sizeof(char));
		if (uidArray[i] == NULL)
		{
			printf("Memory allocation failed for uidArray[%d].\n", i);
			for (int j = 0; j < i; j++)
			{
				free(uidArray[j]);
			}
			free(uidArray);
			free(originalIndex);
			exit(1);
		}
		for (int j = 0; j < sizeof(member->uid); j++)
		{
			copyString(uidArray[i], member[i].uid);
		}
		originalIndex[i] = i;
	}

	// Sorting
	bubbleSort(uidArray, originalIndex, memberCount);

	// Searching
	int foundIndex = binarySearch(uidArray, 0, memberCount - 1, uid);
	if (foundIndex == -1)
	{
		printf("Can't find any member with the given uID\n");
		return -1;
	}
	for (int i = 0; i < memberCount; i++)
	{
		free(uidArray[i]);
	}
	free(uidArray);
	int result = originalIndex[foundIndex];
	free(originalIndex);
	return (result + 1); // Do index bắt đầu từ 0
}

int searchByLicensePlate(const Member *member, const char *licensePlate)
{
	int memberCount = countMemberInArray(member);
	char **uidArray = (char **)malloc(memberCount * sizeof(char *));
	if (uidArray == NULL)
	{
		printf("Memory allocation failed for uidArray.\n");
		exit(1);
	}
	int *originalIndex = (int *)malloc(memberCount * sizeof(int));
	if (originalIndex == NULL)
	{
		printf("Memory allocation failed for originalIndex.\n");
		free(uidArray);
		exit(1);
	}
	for (int i = 0; i < memberCount; i++)
	{
		uidArray[i] = (char *)malloc((sizeof(member->uid) + 1) * sizeof(char));
		if (uidArray[i] == NULL)
		{
			printf("Memory allocation failed for uidArray[%d].\n", i);
			for (int j = 0; j < i; j++)
			{
				free(uidArray[j]);
			}
			free(uidArray);
			free(originalIndex);
			exit(1);
		}
		for (int j = 0; j < sizeof(member->licensePlate); j++)
		{
			copyString(uidArray[i], member[i].licensePlate);
		}
		originalIndex[i] = i;
	}

	// Sorting
	bubbleSort(uidArray, originalIndex, memberCount);

	// Searching
	int foundIndex = binarySearch(uidArray, 0, memberCount - 1, licensePlate);
	if (foundIndex == -1)
	{
		printf("Can't find any member\n");
		return -1;
	}
	for (int i = 0; i < memberCount; i++)
	{
		free(uidArray[i]);
	}
	free(uidArray);
	int result = originalIndex[foundIndex];
	free(originalIndex);
	return result + 1;
}

/*
 * Function: addMember
 * Description: Add a new member to the end of the CSV file
 * Input:
 *   member - a new member struct
 * Output:
 *   An updated CSV file
 */
void addMember(const char *filename, Member member)
{
	FILE *fp = fopen(filename, "a");
	insert1CSVLine(fp, member);
	printf("Added %s successfully", member.name);
}

void addMemberImplement(const char *filename)
{
	Member member;
	printf("Enter the informations of the new resident in the following order: %s\n",
		   MEMBER_INFORMATION);
	scanf(CSV_READ_FORMAT, MEMBER_PRINTF(member));
	addMember(filename, member);
}

/*
 * Function: deleteMember
 * Description: Delete a member base on UID from the CSV file
 * Input:
 *   uid - an UID of a member that need to delete
 * Output:
 *   An updated CSV file
 */
void deleteMember(const char *filename, const char *uid)
{
	int memberCount = countMemberUsingCSV(filename);
	if (memberCount == 0)
	{
		printf("There is no member to delete.\n");
		return;
	}
	else
	{
		Member *member = convertCSVtoArray(filename, memberCount);
		int line = searchByUID(member, uid) + 1; // +1 do bỏ dòng tiêu đề
		if (line == -1)
		{
			return;
		}
		else if (line < 0 || line >= (memberCount + 1))
		{
			printf("Invalid line number: %d\n", line);
			return;
		}
		delete1CSVLine(filename, line);
		Member deletedMember = member[line - 2]; // line đã +1 nên phải -1 và trả về index thì -1
		free(member);
		printf("Deleted %s successfully", deletedMember.name);
	}
}

void deleteMemberImplement(const char *filename)
{
	Member member;
	char *uid = (char *)malloc((sizeof(member.uid) + 1) * sizeof(char));
	printf("Enter the uID of the resident you want to delete: \n");
	scanf("%s", uid);
	deleteMember(filename, uid);
	free(uid);
}

/*
 * Function: editMember
 * Description: Update informations of a member base on UID from the CSV file\
 * Input:
 *   updatedMember - a member struct that need to update
 * Output:
 *   An updated CSV file
 */
void editMember(const char *filename, const char *uid, Member updatedMember)
{
	int memberCount = countMemberUsingCSV(filename);
	if (memberCount == 0)
	{
		printf("There is no member to edit.\n");
		return;
	}
	else
	{
		Member *member = convertCSVtoArray(filename, memberCount);
		int line = searchByUID(member, uid) + 1; // +1 do bỏ dòng tiêu đề
		if (line == -1)
		{
			return;
		}
		if (line < 0 || line >= (memberCount + 1))
		{
			printf("Invalid line number: %d\n", line);
			return;
		}
		Member editMember = member[line - 2]; // line đã +1 nên phải -1 và trả về index thì -1
		modify1CSVLine(filename, line, updatedMember);
		free(member);
		printf("Edited ");
		printf(CSV_WRITE_FORMAT, MEMBER_PRINTF(editMember));
		printf("Into   ");
		printf(CSV_WRITE_FORMAT, MEMBER_PRINTF(updatedMember));
	}
}

void editMemberImplement(const char *filename)
{
	Member member;
	char *uid = (char *)malloc((sizeof(member.uid) + 1) * sizeof(char));
	printf("Enter the uID of the resident you want to edit: \n");
	scanf("%s", uid);
	printf("Enter the informations of the resident in the following order: %s\n",
		   MEMBER_INFORMATION);
	scanf(CSV_READ_FORMAT, MEMBER_PRINTF(member));
	editMember(filename, uid, member);
	free(uid);
}

/*
 * Function: searchMember
 * Description: Find a member informations base on UID or license plate
 * Input:
 *   searchValue - a value from a member that need to be search
 *   searchFunc - function pointer to a search criteria function
 * Output:
 *   A found information or a "Can't found" report
 */
Member searchMember(const char *filename, const char *searchValue,
					SearchFunction searchFunc)
{
	Member result;
	int memberCount = countMemberUsingCSV(filename);
	if (memberCount == 0)
	{
		printf("There is no member to search.\n");
		result.uid[0] = '\0';
		return result;
	}
	else
	{
		Member *member = convertCSVtoArray(filename, memberCount);
		int line = searchFunc(member, searchValue) - 1; // Cần lấy giá trị index
		if (line == -1)
		{
			return result;
		}
		if (line < 0 || line >= (memberCount + 1))
		{
			printf("Invalid line number: %d\n", line);
			result.uid[0] = '\0';
			return result;
		}
		result = member[line];
		free(member);
		return result;
	}
}

int main()
{
	const char *filename = "Resident_Database.csv";
	printf("Apartment resident information management\n");
	PRINT_MENU("Add a resident", "Delete a resident", "Modify a resident's informations", "Search a resident's informations", "Exit");

	int option;
	scanf("%d", &option);

	HANDLE_OPTION(option, filename,
				  CASE_OPTION(1, addMemberImplement)
					  CASE_OPTION(2, deleteMemberImplement)
						  CASE_OPTION(3, editMemberImplement))
	Member member[] = {
		{"12345678906", "A-101", "Lisandro Martinez", "LM06ARG"},
		{"12345678909", "A-102", "Rasmus Hojlund", "RH09DEN"},
		{"12345678910", "A-103", "Marcus Rashford", "MR10ENG"},
		{"12345678907", "A-104", "Mason Mount", "MM07ENG"},
		{"12345678912", "A-105", "Tyrell Malacia", "TM12NED"},
		{"12345678918", "A-106", "Casemiro", "CS18BRA"},
		{"12345678937", "A-107", "Kobbie Mainoo", "KM37ENG"},
		{"12345678902", "A-108", "Victor Lindelof", "VL02SWE"},
		{"12345678915", "A-109", "Leny Yoro", "LY15FRA"},
		{"12345678929", "A-110", "Aaron Wan-Bissaka", "WB29ENG"},
		{"12345678925", "A-111", "Jadon Sancho", "JS25ENG"},
		{"12345678914", "A-112", "Cristian Eriksen", "CE14DEN"},
		{"12345678905", "A-113", "Harry Maguire", "HM05ENG"},
		{"12345678921", "A-114", "Antony", "AT21BRA"},
		{"12345678923", "A-115", "Luke Shaw", "LS23ENG"},
		{"12345678908", "A-116", "Bruno Fernandes", "BF08POR"},
		{"12345678901", "A-117", "Altay Bayindir", "AB01TUR"},
		{"12345678920", "A-118", "Diogo Dalot", "DD20POR"},
		{"12345678916", "A-119", "Amad Diallo", "AD16IVR"},
		{"12345678917", "A-120", "Alejandro Garnacho", "AG17ARG"},
		{'\0'}};
	// for (int i = 0; i < 20; i++)
	// {
	// 	addMember(filename, member[i]);
	// }
	// deleteMember(filename, "12345678925");
	// editMember("Resident_Database.csv", "12345678902", member[1]);
	// printf(CSV_WRITE_FORMAT, MEMBER_PRINTF(searchMember("Resident_Database.csv", "12345678921", searchByUID)));
}