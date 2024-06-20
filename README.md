# Avanced C/C++
## Bài 1: Compiler Process
### Compiler
Máy tính không thể hiểu được những đoạn code mà chúng ta viết, chúng chỉ hiểu được những **mã máy**. Vậy nên, phải cần có một quá trình dịch những đoạn code ta viết thành mã máy. Đó là quá trình **COMPILE**.

Quá trình compile bao gồm các bước như sau (sử dụng toolchain là gcc):
- **Preprocessing**: chuyển đổi các file .c .h .cpp .hpp,... thành các file .i .ii. Bước này cơ bản là chèn nội dung của các file được "#include" vào file output, thay thế nội dung đã được khai báo của các macro và xoá các dòng comment có trong chương trình.
$$gcc\space{-}E\space{<}input.c{>}\space{-}o\space{<}output.i{>}$$
- **Compile**: dịch các file .i .ii thành các file ngôn ngữ assembly .s.
$$gcc\space{<}input.i{>}\space{-}S\space{-}o\space{<}output.s{>}$$
- **Assembler**: dịch file assembly .s thành mã máy .o. File mã máy bao gồm 2 thành phần chính là địa chỉ thanh ghi và giá trị tại địa chỉ đó. File mã máy có thể ở 2 dạng là mã nhị phân (bin) và mã 16 (hex).
$$gcc\space{-}c\space{<}input.s{>}\space{-}o\space{<}output.o{>}$$
- **Linker**: liên kết các file mã máy .o lại để tạo thành một file có thể xuất được .exe. Những file .exe là những file được nạp cho máy tính để máy tính có thể xử lý.
$$gcc\space{<}input1.o{>}\space{<}input2.o{>}{...}\space{-}o\space{<}output{>}$$
Note: Để chạy file .exe trên VS Code để debug thì nhập câu lệnh: ./${<}output{>}$
