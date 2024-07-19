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

#define CSV_FORMAT "%s,%s,%s,%s\n"
#define MEMBER_INFORMATION(member) member.uid, member.roomNumber, member.name, member.licensePlate

typedef struct
{
    char uid[20];          // UID của RFID
    char roomNumber[10];   // Số Phòng
    char name[50];         // Tên
    char licensePlate[20]; // Biển Số Xe
} Member;

typedef struct MemberNode
{
    Member data;
    struct MemberNode *next;
} MemberNode;

typedef int (*SearchFunction)(const Member *, const char *);

MemberNode *list;

void insert1CSVLine(FILE *fp, Member member)
{
    fprintf(fp, CSV_FORMAT, MEMBER_INFORMATION(member));
    fclose(fp);
}

int isNoMember(const char *filename)
{
}

/*
* Function: createMemberNode
* Description:  This function create a new node at the end of the database\
                that contain a member informations.
* Input:
*   member - a member struct
* Output:
*   returns a new member node
*/
MemberNode *createMemberNode(Member member)
{
    MemberNode *newNode = (MemberNode *)malloc(sizeof(MemberNode));
    newNode->data = member;
    newNode->next = NULL;
    return newNode;
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
    MemberNode *newNode;
    newNode = createMemberNode(member);

    if (isNoMember == 0)
    {
        MemberNode *p = list;
        while (p->next != NULL)
        {
            p = p->next;
        }

        p->next = newNode;
    }
    else
        list = newNode;
    FILE *fp = fopen(filename, "a");
    insert1CSVLine(fp, member);
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
    /*
     * Ý tưởng là như này:
     *   - Tạo cái mảng mới xài malloc() để lưu cái list y chang cái gốc
     *   - Sắp xếp các node theo thứ tự tăng dần (theo ASCII)
     *   - Binary Search cái mảng mới. Tạo hàm bubbleSort(), hàm binarySearch()
     *   - Ra được thằng cần tìm thì free() bộ nhớ
     */
}

/*
 * Function: editMember
 * Description: Update informations of a member base on UID from the CSV file\
 * Input:
 *   updatedMember - a member struct that need to update
 * Output:
 *   An updated CSV file
 */
void editMember(const char *filename, Member updatedMember)
{
}

int searchByUID(const Member *member, const char *uid)
{
}

int searchByLicensePlate(const Member *member, const char *licensePlate)
{
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
}

int main()
{
    Member member = {
        .uid = "123456789",
        .roomNumber = "A-101",
        .name = "Vo Thanh Danh",
        .licensePlate = "M10ARG"};
    MemberNode memberNode;
    // addMember("Resident_Database.csv", member);
}