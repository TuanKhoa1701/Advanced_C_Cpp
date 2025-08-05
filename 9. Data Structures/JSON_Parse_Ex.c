#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
#include <ctype.h>

typedef enum{
    JSON_NULL,
    JSON_BOOLEAN,
    JSON_NUMBER,
    JSON_STRING,
    JSON_ARRAY,
    JSON_OBJECT
}Json_type;


typedef struct Json_value { // định nghĩa kiểu dữ liệu Json_value, không có dòng này sau struct thì C sẽ không
    Json_type type;         // hiểu việc định nghĩa nếu có dùng lại kiểu Json_value ở trong struct
    union {
        bool boolean;
        double number;
        char *string;
        struct {
            struct Json_value *values;// như này
            size_t size;
        } array;
        struct{
            char **keys;
            struct Json_value *values;
            size_t size;
        } Object;
    }value;
} Json_value;   // viết ko như này thì ở dưới có thể dùng Json_Value nhưng bên trong struct sẽ không hiểu

Json_value *Json_parse(const char **json_string);

void free_Json_value(Json_value *value);

static void skip_whitespace(const char **json_string) {
    while (isspace(**json_string)) {
        (*json_string)++;
    }
}   
Json_value *parse_NULL(const char ** Json){
    skip_whitespace(Json);
    if(strncmp(*Json,"null",4)==0){
        Json_value *value = (Json_value *)malloc(sizeof(Json_value));
        value -> type = JSON_NULL;
        *Json += 4;
        return value;
    }
        return NULL;
}
Json_value *parse_boolean(const char **Json){  // có tí thay đổi về mặt logic
    skip_whitespace(Json);
    Json_value *value = (Json_value *)malloc(sizeof(Json_value));
    if(strncmp(*Json,"true",4)==0){
        value -> type = JSON_BOOLEAN;
        value -> value.boolean =true;
        *Json += 4;
        return value;
    }
    else if(strncmp(*Json,"false",5)==0){
            value -> type = JSON_BOOLEAN;
            value -> value.boolean = false;
            *Json += 5;
            return value;
    }
    else {
        free(value);
        return NULL;
    }
}
Json_value *parse_number(const char ** Json){
    skip_whitespace(Json);
    char *end;
    double number = strtod(*Json, &end);
    if(end != *Json){
        Json_value *value = (Json_value *)malloc(sizeof(Json_value));
        value -> type = JSON_NUMBER;
        value -> value.number = number;
        *Json = end;
        return value;        
    }
    else {
        return NULL;
    }
}
Json_value *parse_string(const char **Json){
    skip_whitespace(Json);
    if(**Json == '\"'){
    (*Json)++;
    const char *start = *Json;
    while(**Json != '\"' && **Json != '\0'){
        (*Json)++;
        }
        if(**Json == '\"'){
            size_t length = *Json - start;
            char* str = (char *)malloc((length + 1) * sizeof(char));
            strncpy(str, start, length);
            str[length] = '\0';

            Json_value *value = (Json_value *)malloc(sizeof(Json_value));
            value -> type = JSON_STRING;
            value -> value.string = str;
            (*Json)++;
            return value;
        }
   
    } 
                return NULL; // Missing closing quote
}
Json_value *parse_array(const char ** Json){
    skip_whitespace(Json);
    if(**Json == '['){
    (*Json) += 1;
    skip_whitespace(Json);
    Json_value *array_value = (Json_value *)malloc(sizeof(Json_value));
    array_value->type = JSON_ARRAY;
    array_value->value.array.size = 0;
    array_value->value.array.values = NULL;
        while (**Json != ']' && **Json != '\0'){
        Json_value *elements = Json_parse(Json);
        if(elements){
        array_value->value.array.size++;
        array_value->value.array.values = (Json_value *)realloc(array_value->value.array.values, array_value->value.array.size * sizeof(Json_value));
        array_value->value.array.values[array_value->value.array.size - 1] = *elements;
        free(elements);
        }
        else{
            break;
        }
        skip_whitespace(Json);   
            if(**Json == ','){
                (*Json)++;
            }
        }
        if(**Json == ']'){
            (*Json)++;
            return array_value;
        }
        else {
            free_Json_value(array_value);
            return NULL; // Missing closing bracket
        }
    }
    return NULL; // Not an array
}
Json_value *parse_object(const char **Json){
    skip_whitespace(Json);
    if(**Json == '{'){
        (*Json)++;
        skip_whitespace(Json);
        Json_value* object_value = (Json_value*)malloc(sizeof(Json_value));
        object_value-> type = JSON_OBJECT;
        object_value->value.Object.size = 0;
        object_value->value.Object.keys = NULL;
        object_value->value.Object.values = NULL;
        while(**Json != '}' && **Json != '\0'){
            Json_value *key = parse_string(Json);
            if(key){
                skip_whitespace(Json);
                if(**Json == ':'){
                    (*Json)++;
                    Json_value *value = Json_parse(Json);
                    if(value){
                        object_value -> value.Object.size++;

                        object_value -> value.Object.keys = (char**)realloc(object_value->value.Object.keys, object_value->value.Object.size * sizeof(char*));
                        object_value -> value.Object.keys [object_value->value.Object.size - 1] = key->value.string;

                        object_value -> value.Object.values = (Json_value *)realloc(object_value -> value.Object.values, object_value -> value.Object.size * sizeof(Json_value));
                        object_value -> value.Object.values[object_value -> value.Object.size - 1] = *value;
                        free(value);
                    }
                else{
                    free_Json_value(key);
                    break;
                }   
                }
                else {
                    free_Json_value(key);
                    break; // Missing colon
                }
            }
            else {
                break; // Missing key
            }
            skip_whitespace(Json);
            if(**Json == ','){
                (*Json)++;            
            }
        }
        if(**Json == '}'){
            (*Json)++;
            return object_value;
        }
        else {
            free_Json_value(object_value);
            return NULL; // Missing closing brace
    }
    return NULL; // Not an object
    }
}

Json_value *Json_parse(const char **json){
    while (isspace(**json))
    {
        (*json)++;
    }

    switch (**json)
    {
    case 'n':
        return parse_NULL(json);
    case 't':
    case 'f':
        return parse_boolean(json);
    case '\"':
        return parse_string(json);
    case '[':
        return parse_array(json);
    case '{':
        return parse_object(json);
    default:
        if (isdigit(**json) || **json == '-')
        {
            return parse_number(json);
        }
        else
        {      // Lỗi phân tích cú pháp
            return NULL;
        }
    }
}
//////////////
/////////////
void free_Json_value(Json_value *value){
    if(value == NULL) return;
    switch (value->type)
    {
        case JSON_STRING:
            free(value->value.string);
            break;
        case JSON_ARRAY:
            for (size_t i = 0; i < value->value.array.size; i++)
            {
                free_Json_value(&value->value.array.values[i]);
            }
            free(value->value.array.values);
            break;
        case JSON_OBJECT:
            for (size_t i = 0; i < value->value.Object.size; i++)
            {
                free(value->value.Object.keys[i]);
                free_Json_value(&value->value.Object.values[i]);
            }
            free(value->value.Object.keys);
            free(value->value.Object.values);
            break;
        default:
            break;
    }
}
void test(Json_value *value){
    if(value != NULL && value -> type == JSON_OBJECT){
        size_t num_fields = value -> value.Object.size;
        size_t num_fields2 = value -> value.Object.values->value.Object.size;
        for(size_t i =0; i < num_fields;i++){
            char* key = value -> value.Object.keys[i];
            Json_value *val = &value -> value.Object.values[i];
            Json_type type = (int) (value->value.Object.values[i].type);
        if(type == JSON_STRING) 
            printf("%s: %s\n", key, val->value.string);
        if(type == JSON_NUMBER)
            printf("%s: %f\n", key, val->value.number);
        if(type == JSON_BOOLEAN)
            printf("%s: %s\n", key, val->value.boolean ? "true" : "false");
        if(type == JSON_OBJECT){
            printf("%s:\n", key);
            test(val);
        }
        if(type == JSON_ARRAY){
            printf("%s:", key);
            for(int i=0; i< val-> value.array.size; i++){
                test(val->value.array.values + i);
            }
            printf("\n");
        }
    }
}
else{
    if(value ->type == JSON_STRING)
        printf("%s\n", value->value.string);
    if(value ->type == JSON_NUMBER)
        printf("%f\n", value->value.number);
    if(value ->type == JSON_BOOLEAN)
        printf("%s\n", value->value.boolean ? "true" : "false");
    if(value ->type == JSON_OBJECT){
        printf("%s:\n", value->value.Object.keys);
        test(value->value.Object.values);
        }
    }
}

int main(int argc, char const *argv[])
{
    // Chuỗi JSON đầu vào

    const char *json_str = "{"
                           "\"1001\":{"
                           "\"SoPhong\":3,"
                           "\"NguoiThue\":{"
                           "\"Ten\":\"Nguyen Van A\","
                           "\"CCCD\":\"1920517781\","
                           "\"Tuoi\":26,"
                           "\"ThuongTru\":{"
                           "\"Duong\":\"73 Ba Huyen Thanh Quan\","
                           "\"Phuong_Xa\":\"Phuong 6\","
                           "\"Tinh_TP\":\"Ho Chi Minh\""
                           "}"
                           "},"
                           "\"SoNguoiO\":{"
                           "\"1\":\"Nguyen Van A\","
                           "\"2\":\"Nguyen Van B\","
                           "\"3\":\"Nguyen Van C\""
                           "},"
                           "\"TienDien\": [24, 56, 98],"
                           "\"TienNuoc\":30.000"
                           "},"
                           "\"1002\":{"
                           "\"SoPhong\":5,"
                           "\"NguoiThue\":{"
                           "\"Ten\":\"Phan Hoang Trung\","
                           "\"CCCD\":\"012345678912\","
                           "\"Tuoi\":24,"
                           "\"ThuongTru\":{"
                           "\"Duong\":\"53 Le Dai Hanh\","
                           "\"Phuong_Xa\":\"Phuong 11\","
                           "\"Tinh_TP\":\"Ho Chi Minh\""
                           "}"
                           "},"
                           "\"SoNguoiO\":{"
                           "\"1\":\"Phan Van Nhat\","
                           "\"2\":\"Phan Van Nhi\","
                           "\"2\":\"Phan Van Tam\","
                           "\"3\":\"Phan Van Tu\""
                           "},"
                           "\"TienDien\":23.000,"
                           "\"TienNuoc\":40.000"
                           "}"
                           "}";

    // Phân tích cú pháp chuỗi JSON
    Json_value *json_value = Json_parse(&json_str);

    test(json_value);

    // Kiểm tra kết quả phân tích cú pháp

    // Giải phóng bộ nhớ được cấp phát cho JsonValue
    free_Json_value(json_value);

    // printf("test = %x", '\"');

    // hienthi(5);

    return 0;
}
