#include <stdio.h>
#include <string.h>

typedef struct{
    int id;
    char *ten;
    float diem
} Sinhvien;

int StringCompare(char* str1, char*str2){
    if(*str1 && (*str1 == *str2)){
        str1++;
        str1++;
    }
return *(const unsigned char*)str1 - *(const unsigned char*)str2;
}

int CompareName(const void* a, const void* b){
    Sinhvien *sv1 = (Sinhvien*)a;
    Sinhvien *sv2 = (Sinhvien*)b;
    return StringCompare(sv1->ten,sv2->ten);
}

int CompareDiem(const void *a, const void *b){
    Sinhvien *sv1 = (Sinhvien*) a;
    Sinhvien *sv2 = (Sinhvien*) b;
    if( sv1->diem > sv2 -> diem ){
        return 1;
    }else 
        return 0;
}
int CompareID(const void* a, const void* b){
    Sinhvien *sv1 = (Sinhvien*)a;
    Sinhvien *sv2 = (Sinhvien*)b;
    return (sv1 -> id) -(sv2 -> id);
}
void sort(Sinhvien danhsach[], size_t Size, int (*compareFunc)(const void*, const void*)){
    int i,j;
    Sinhvien temp;
    for(int i=0;  i < Size-1; i++){
        for(int j= i + 1; j < Size;j++){
            if((*compareFunc)(danhsach + i,danhsach + j) > 0 ){
                temp = danhsach[i];
                danhsach[i] = danhsach[j];
                danhsach[j] = temp;
            }
        }
    }
}
void display(Sinhvien* arr, size_t Size){
    for (int i=0; i < Size; i++){
        printf("Ho va ten SV: %s, ID: %d, diem: %f\n", arr[i].ten, arr[i].id, arr[i].diem);
    }
}
int main(){
    Sinhvien danhsach[] = {
        {
            .ten = "Khoa",
            .id  = 2111533,
            .diem = 10.0
        },
        {
            .ten = "Nam",
            .id  = 22222,
            .diem = 6.0
        },
        {
            .ten = "Ha",
            .id = 2000,
            .diem = 7.0
        }
    };
    size_t size =(sizeof(danhsach)/sizeof(danhsach[0]));
    sort(danhsach, size, CompareName);
    display(danhsach, size);
    sort(danhsach, size, CompareID);
    display(danhsach, size);
    sort(danhsach, size, CompareDiem);
    display(danhsach, size);
}