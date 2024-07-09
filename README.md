# Avanced C/C++
## Bài 1: Compiler Process
### Compiler
Máy tính không thể hiểu được những đoạn code mà chúng ta viết, chúng chỉ hiểu được những **mã máy**. Vậy nên, phải cần có một quá trình dịch những đoạn code ta viết thành mã máy. Đó là quá trình **COMPILE**.

Quá trình compile bao gồm các bước như sau (sử dụng toolchain là gcc):
- **Preprocessing**: chuyển đổi các file .c .h .cpp .hpp,... thành các file .i .ii. Bước này cơ bản là chèn nội dung của các file được "#include" vào file output, thay thế nội dung đã được khai báo của các macro và xoá các dòng comment có trong chương trình.
```
    gcc -E <input.c> -o <output.i>
```
- **Compile**: dịch các file .i .ii thành các file ngôn ngữ assembly .s.
```
    gcc <input.i> -S -o <output.s>
```
- **Assembler**: dịch file assembly .s thành mã máy .o. File mã máy bao gồm 2 thành phần chính là địa chỉ thanh ghi và giá trị tại địa chỉ đó. File mã máy có thể ở 2 dạng là mã nhị phân (bin) và mã 16 (hex).
```
    gcc -c <input.s> -o <output.o>
```
- **Linker**: liên kết các file mã máy .o lại để tạo thành một file có thể xuất được .exe. Những file .exe là những file được nạp cho máy tính để máy tính có thể xử lý.
```
    gcc <input1.o> <input2.o>... -o <output.s>
```
Note: Nếu muốn chạy file .exe trên VS Code để debug thì nhập câu lệnh: ./\<output\>

### Macro
**MACRO** là những thông tin được xử lý trong bước **Preprocessing** của quá trình **COMPILE**. Có những macro sau:
- #include: khi preprocessing, editor sẽ chèn nội dung của một file vào chương trình. Macro này giúp chia nhỏ chương trình chính thành những file nhỏ hơn để dễ dàng quản lý và có thể tái sử dụng ở những dự án khác.

- #define: định nghĩa một chuỗi code bằng một chuỗi code khác giúp code được gọn, debug dễ. Khi preprocessing, những chuỗi được #define sẽ được thay thế bằng định nghĩa của chúng.

- #undef: xoá định nghĩa trước đó của chuỗi.

- #ifdef, #ifndef: check xem chuỗi đó đã được định nghĩa chưa, nếu có (#ifdef) hoặc không (#ifndef) thì sẽ biên dịch chương trình sau macro cho tới #endif.

- #if, #elif, #else: nếu điều kiện #if đúng thì sẽ biên dịch chương trình sau đó, nếu sai thì bỏ qua và xét tới các #elif, nếu tất cả sai thì biên dịch chương trình sau #else cho tới khi gặp #endif.

Các toán tử của macro: (Xem ví dụ ở folder bài 1)
- Có thể khai báo macro có tham số bằng cách bỏ chúng giữa () sau tên macro (giống với cách khai báo hàm nhưng không thêm kiểu biến).
- Nếu muốn viết macro nhiều dòng thì chèn ký tự "\" vào cuối mỗi dòng của định nghĩa (ngoại trừ dòng cuối).
- Toán tử #: chuẩn hoá biến hoặc chuỗi ký tự sau nó thành dạng string khi preprocessing (đặt chúng giữa "").
- Toán tử ##: nối 2 chuỗi ký tự trước và sau ## lại, thường được dùng để nối 1 chuỗi ký tự với tên 1 biến.

Ngoài ra, có thể sử dụng "\_\_VA_ARGS\_\_" để thay thế cho số lượng tham số không biết trước, dành cho những hàm hay macro mà ta không biết trước số lượng tham số truyền vào hàm.

## Bài 2: Advanced Function Concepts and Debug
### Thư viện stdarg
**STDARG** cung cấp khả năng viết những hàm mà không biết trước số lượng tham số truyền vào hàm.

- **va_list**: là 1 kiểu dữ liệu làm đại diện cho các tham số truyền vào.
```
    va_list <args>;
```
- **va_start**: là nơi chỉ định điểm bắt đầu của danh sách tham số, cần được gọi trước khi truy cập vào bất cứ tham số nào.
    ```
        va_start(args, label);
    ```
    - **args** là tên danh sách kiểu va_list đã được khai báo ở trên.
    - **label** là tên biến của điểm bắt đầu của danh sách tham số sẽ được truy cập bằng va_arg.


- **va_arg**: truy cập 1 tham số trong danh sách tham số. Ban đầu, con trỏ va_arg sẽ đi tới điểm bắt đầu là "label" trong va_start và đọc biến tiếp theo trong danh sách. Sau khi đọc xong, con trỏ va_arg sẽ tự động +1 để đi tiếp trong danh sách.
```
    va_arg(args, typedef)
```
**typedef** là kiểu dữ liệu của tham số cần đọc, nếu typedef khác với kiểu dữ liệu của tham số cần đọc thì giá trị trả về sẽ là giá trị rác.

- **va_end**: kết thúc việc sử dụng danh sách tham số và được gọi ngay trước khi kết thúc hàm. Khi gọi va_end, giá trị con trỏ va_arg sẽ được thu hồi về điểm bắt đầu của va_list.
```
    va_end(args);
```
### Thư viện assert
**ASSERT** cung cấp khả năng dừng chương trình và thông báo lỗi khi gặp một điều kiện nhất định. Nếu điều kiện của assert thoả, chương trình sẽ dừng lại và thông báo một thông điệp lỗi.
```
    va_arg(args, typedef)
```
**ASSERT** được dùng để debug, có thể để phòng ngừa những lỗi thuật toán hay lỗi toán học như chia cho 0. Để tắt tính năng debug thì dùng #define NDEBUG
## Bài 3: Advanced Pointer
**Pointer (Con trỏ)** là một biến lưu giá trị địa chỉ bộ nhớ của biến khác. Pointer giúp các thao tác trên bộ nhớ được linh hoạt hơn. Kích thước của con trỏ phụ thuộc vào kiến trúc máy tính và trình biên dịch.\
Cách khai báo:
```
    int *ptr = &value;
```
Sử dụng ký tự & giúp ta lấy được địa chỉ của biến đằng sau &. Ở ví dụ trên, biến con trỏ tên "ptr" có giá trị là địa chỉ của một biến khác tên là "test".\
Ta có thể lấy địa chỉ của biến "test" thông qua con trỏ "ptr" như sau:
```
    int address = ptr;
```
Để truy cập đến giá trị của biến "test", ta có thể sử dụng biến con trỏ "ptr" như sau:
```
    *ptr = 6;
```
Sử dụng ký tự * giúp ta truy cập được giá trị của biến được biến con trỏ chỉ tới (dereference). Ở đây, ta sử dụng con trỏ "ptr" để truy cập vào giá trị của biến "test" và thay đổi nó bằng 6.\
- **void pointer (con trỏ void)** là biến con trỏ có thể trỏ tới địa chỉ của mọi kiểu dữ liệu. Cách khai báo giống với khai báo con trỏ bình thường nhưng thay kiểu dữ liệu bằng "void"
```
    void *ptr;
```
Tuy nhiên, nếu muốn truy cập đến giá trị của của biến thông qua void pointer thì ta phải ép kiểu dữ liệu của nó:
```
    int value = 5;
    void *ptr = &value;
    *(int*)(ptr) = 10;
```
Ở đây, ta vừa ép kiểu "ptr" là pointer to integer để nó có thể truy cập đến giá trị của "value" và đọc nó dưới dạng số nguyên.
- **Function Pointer (con trỏ hàm)** là biến con trỏ lưu địa chỉ của một hàm. Con trỏ hàm cho phép bạn truyền một hàm như là một đối số cho một hàm khác, lưu trữ địa chỉ của hàm trong một cấu trúc dữ liệu, hoặc thậm chí truyền hàm như một giá trị trả về từ một hàm khác.\
Cách khai báo con trỏ hàm phụ thuộc vào kiểu giá trị trả về của hàm và các kiểu dữ liệu của các tham số truyền vào hàm. Ví dụ:
```
    void function1();
    int function2(int a, int b);

    void (*ptrToFunction1)();
    int (*ptrToFunction2)(int, int);
```
Ta gán địa chỉ cho con trỏ hàm như sau:
```
    ptrToFunction1 = function1;
    ptrToFunction2 = function2;
```
Để truy xuất (thực thi) hàm thông qua con trỏ hàm ta làm như sau:
```
    (*ptrToFunction1)();
    (*ptrToFunction2)(4, 5);
```
Có thể hiểu () được dùng để truy xuất một hàm nào đó.
- **Pointer to Constant (con trỏ đến hằng)** là một con trỏ chỉ tới vùng nhớ hằng, tức là giá trị trong địa chỉ vùng nhớ đó không thể thay đổi. Tuy nhiên, pointer to constant có thể thay đổi địa chỉ mà nó trỏ tới.\
Cách khai báo:
```
    int const *ptr = &value;
    const int *ptr = &value;
```
- **Constant Pointer (con trỏ hằng)** là một con trỏ không thể thay đổi giá trị của nó, tức là không thể thay đổi địa chỉ mà nó trỏ đến. Có thể nói Constant Pointer là ngược lại với Pointer to Constant.\
Cách khai báo:
```
    int *const ptr = &value;
```
- **Pointer to pointer (con trỏ đến con trỏ)** là một con trỏ lưu giá trị địa chỉ của một con trỏ khác.\
Cách khai báo:
```
    int **ptr = &ptr1;
```
- **NULL Pointer** là một con trỏ không trỏ đến bất cứ đối tượng nào. Khi khai báo một pointer thì ta phải gán giá trị cho pointer đó hoặc là gán NULL cho pointer đó để tránh *Dangling Pointer (con trỏ lơ lửng)*. Dangling pointer chứa giá trị rác và khi dereference nó thì sẽ dẫn đến những hành vi không xác định có thể gây sập chương trình. Ngoài ra, NULL pointer có thể giúp kiểm soát pointer, cho ta biết là pointer đã được khởi tạo và đã có giá trị hợp lệ hay chưa.
## Bài 4: Storage Classes
### Extern
**Extern** là một từ khoá dùng để báo cho trình biên dịch biết là đối tượng đằng sau extern đã được khai báo hay định nghĩa ở một nơi khác trong chương trình hoặc ở file khác. Sau khi khai báo extern với đối tượng nào đó thì ta có thể sử dụng đối tượng đó trong vị trí chương trình hiện tại.\
Cách khai báo:
```
    extern int test;
    extern void function1();
    extern int functoin2(int, int);
```
### Static
- **Static Local (biến static cục bộ)** là một biến cục bộ có giá trị được giữ lại qua những lần gọi. Giải thích:
    - Khi khai báo biến cục bộ không kèm từ khoá *static*, địa chỉ của biến sẽ được lưu vào phân vùng *stack*. Phân vùng stack sẽ thu hồi địa chỉ của biến cục bộ sau khi chương trình rời khỏi khu vực cục bộ của biến đó, nên sau khi thoát khỏi khu vực cục bộ này, địa chỉ của biến sẽ bị thu hồi và khi gọi lại khu vực cục bộ đó, máy tính sẽ khởi tạo lại biến đấy và mọi giá trị trước đó sẽ mất.
    - Biến được khai báo static sẽ được lưu vào phân vùng *bss* (nếu bằng 0) hoặc *data* (nếu khác 0). 2 phân vùng này có điểm chung là sẽ chỉ thu hồi địa chỉ của biến sau khi chương trình kết thúc. Vì vậy, qua những lần gọi khu vực cục bộ khác nhau, địa chỉ của biến chưa bị thu hồi nên giá trị của biến tại địa chỉ đó chưa mất đi.
- **Static Global (biến static toàn cục)** là một biến toàn cục bị hạn chế phạm vi sử dụng chỉ trong file khai báo nó. Một biến toàn cục có thể dễ dàng được sử dụng bởi các file khác thông qua từ khoá *extern*, tuy nhiên khi khai báo biến toàn cục với *static*, nó sẽ chỉ cho phép file khai báo nó và không cho phép các file khác truy cập.
### Volatile
Việc tối ưu hoá chương trình giúp tăng hiệu suất chương trình. Khi biến được khai báo kèm với từ khoá **volatile**, ta báo cho trình biên dịch biết rằng biến này có thể bị thay đổi bất ngờ hoặc không theo một quy luật nào đó của trình biên dịch, cho nên là đừng tối ưu biến đó. Điều này đảm bảo khi đọc giá trị biến này thì ta đang đọc giá trị mới nhất từ bộ nhớ của nó.
Volatile được sử dụng nhiều khi biến này được sử dụng chung giữa ngắt và chương trình chính hoặc là được sử dụng cho các thanh ghi phần cứng, nơi mà thường thay đổi giá trị mà không tuân theo các quy tắc lập trình thông thường.
```
    volatile int test;
```
### Register
- Khi một biến được khai báo bình thường, biến đó sẽ được lưu vào bộ nhớ RAM. Tuy nhiên khi muốn truy cập đến một biến nào đó, ta truy cập thanh ghi CPU sẽ nhanh hơn truy cập bộ nhớ RAM. Ngoài ra khi thực hiện các phép tính toán, CPU sẽ phải lưu biến đó vào 1 thanh ghi CPU và liên kết nó với biến trên RAM, sau đó từ thanh ghi sẽ đưa đến bộ ALU để tính toán và cập nhật lại trên thanh ghi, và từ thanh ghi sẽ trả lại giá trị về cho RAM. Điều này sẽ gây mất thời gian khi ta phải thực hiện phép toán nhiều lần trong khoảng thời gian ngắn.
- Khi một biến được khai báo kèm từ khoá **register** ở phía trước, nó sẽ báo cho trình biên dịch biết rằng biến này sẽ được lưu vào 1 thanh ghi trên CPU. Điều này sẽ giúp việc truy cập đến biến đó sẽ diễn ra nhanh hơn. Tuy nhiên, trình biên dịch sẽ tối ưu hoá biến này khi không còn chỗ trên CPU hoặc thấy hiệu suất sử dụng của nó là không thoả đáng. Ngoài ra, ta không thể lấy địa chỉ của biến bằng toán tử "&" vì thanh ghi CPU không có địa chỉ bộ nhớ như RAM.
- Các biến register có thể được sử dụng để giảm thời gian tính toán nhiều trong khoảng thời gian ngắn như vòng lặp hoặc để ứng dụng trong những dự án cần hoạt động nghiêm khắc ở thời gian thực.
