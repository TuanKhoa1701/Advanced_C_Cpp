# Avanced C/C++
## Bài 1: Compiler Process
### Compiler
Máy tính không thể hiểu được những đoạn code mà chúng ta viết, chúng chỉ hiểu được những **mã máy**. Vậy nên, phải cần có một quá trình dịch những đoạn code ta viết thành mã máy. Đó là quá trình **COMPILE**.

Quá trình compile bao gồm các bước như sau (sử dụng toolchain là gcc):
- **Preprocessing**: chuyển đổi các file .c .h .cpp .hpp,... thành các file .i .ii. Bước này cơ bản là chèn nội dung của các file được "#include" vào file output, thay thế nội dung đã được khai báo của các macro và xoá các dòng comment có trong chương trình.
####
    gcc -E <input.c> -o <output.i>

- **Compile**: dịch các file .i .ii thành các file ngôn ngữ assembly .s.
####
    gcc <input.i> -S -o <output.s>

- **Assembler**: dịch file assembly .s thành mã máy .o. File mã máy bao gồm 2 thành phần chính là địa chỉ thanh ghi và giá trị tại địa chỉ đó. File mã máy có thể ở 2 dạng là mã nhị phân (bin) và mã 16 (hex).
####
    gcc -c <input.s> -o <output.o>

- **Linker**: liên kết các file mã máy .o lại để tạo thành một file có thể xuất được .exe. Những file .exe là những file được nạp cho máy tính để máy tính có thể xử lý.
####
    gcc <input1.o> <input2.o>... -o <output.s>

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
####
    va_list <args>;

- **va_start**: là nơi chỉ định điểm bắt đầu của danh sách tham số, cần được gọi trước khi truy cập vào bất cứ tham số nào.
####
    va_start(args, label);

**args** là tên danh sách kiểu va_list đã được khai báo ở trên.
**label** là tên biến của điểm bắt đầu của danh sách tham số sẽ được truy cập bằng va_arg.


- **va_arg**: truy cập 1 tham số trong danh sách tham số. Ban đầu, con trỏ va_arg sẽ đi tới điểm bắt đầu là "label" trong va_start và đọc biến tiếp theo trong danh sách. Sau khi đọc xong, con trỏ va_arg sẽ tự động +1 để đi tiếp trong danh sách.
####
    va_arg(args, typedef)

**typedef** là kiểu dữ liệu của tham số cần đọc, nếu typedef khác với kiểu dữ liệu của tham số cần đọc thì giá trị trả về sẽ là giá trị rác.

- **va_end**: kết thúc việc sử dụng danh sách tham số và được gọi ngay trước khi kết thúc hàm. Khi gọi va_end, giá trị con trỏ va_arg sẽ được thu hồi về điểm bắt đầu của va_list.
####
    va_end(args);

### Thư viện assert
**ASSERT** cung cấp khả năng dừng chương trình và thông báo lỗi khi gặp một điều kiện nhất định. Nếu điều kiện của assert thoả, chương trình sẽ dừng lại và thông báo một thông điệp lỗi.
####
    va_arg(args, typedef)

**ASSERT** được dùng để debug, có thể để phòng ngừa những lỗi thuật toán hay lỗi toán học như chia cho 0. Để tắt tính năng debug thì dùng #define NDEBUG