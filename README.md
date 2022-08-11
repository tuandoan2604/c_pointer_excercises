# c_pointer_excercises

## Basic

## Exercise 1: 
  Mục đích: Luyện tập với Function, Function Closure
  Dãy số fibonacci là dãy số được tạo bằng cách như sau:
  1. Hai số đầu tiên là số 1.
  3. Các số tiếp theo lần lượt được tạo thành từ tổng của 2 số trước nó.
  3. Dãy fibonacci: 1, 1, 2, 3, 5, 8, 13, 21, ...
  Viết một chương trình in ra dãy fibonacci mà khi ta nhập số n sẽ in ra số dãy Fibonacci đến số thứ n (Có thể thực hiện điều này bằng giải thuật đệ quy).
  Input: Số nguyên n
  Ouput: Dãy Fibonacci từ số fibonacci thứ 1 tới số fibonacci thứ n.

## Exercise 2: 
  Mục đích: Làm việc với Bitwise
  Yêu cầu: Số nguyên a được nhập từ bàn phím:
  1. Đếm số bit có giá trị 1 và in ra màn hình
  2. Viết chương trình thay đổi giá trị bit thứ 4 từ phải qua của a về 0 và hiển thị ra màn hình giá trị của biến a. 
  3. Viết chương trình thay đổi giá trị bit thứ 5 từ phải qua của a về 1 và hiển thị ra màn hình giá trị của biến a.
  4. Viết chương trình đảo giá trị bit thứ 3 từ phải qua của a về 0 và hiển thị ra màn hình giá trị của biến a.
  5. Chỉ sử dụng Bitwise để thay đổi số 0x1234 thành 0x3412 và 0x4321.
  Input: Số nguyên a
  Ouput: Thực hiện các phép thao tác bit với yêu cầu đề bài

## Exercise 3: 
  Mục đích: Luyện tập về Struct, Basic Data Types, switch case, thuật toán sắp xếp, làm việc với file. 
  Yêu cầu: Viết chương trình dạng menu cho phép sử dụng các tính năng như sau:
  Kiểu dữ liệu Student có các trường họ tên, giới tính, tuổi, điểm toán – lý – hóa và điểm trung bình.
  1. Nhập vào danh sách N sinh viên
  2. Xuất danh sách N sinh viên
  3. Tính điểm trung bình cho N sinh viên
  4. Sắp xếp N sinh viên theo thứ tự tăng dần của điểm trung bình, theo tên, theo họ, theo tuổi.
  5. Xếp loại N sinh viên
  6. Xuất danh sách N sinh viên ra file

  Input: Dữ liệu của sinh viên tên, tuổi, điểm,…
  Ouput: Danh sách sinh viên có sắp xếp theo tên, điểm ,… và lưu dưới dạng File

## Exercise 4: 
  Mục đích: Làm việc với File trong C++, xử lý chuỗi, mảng ký tự, Slice, If statement, For Loop, Error Handling.
  Yêu cầu: viết chương trình hiển thị file .hex, được format theo dạng intel hex file
  1.	Chương trình sẽ mở một file vào và tìm hiểu xem file đấy có phải là file hex không bằng cách dùng “error” (Tạo một type và biến nó thành error: Ví dụ: type ErrHexFileFormat Int )? 
  Sau đó chương trình sẽ đọc từng dòng của file và cuối cùng hiển thị file đấy lên trên màn hình. Định dạng của hiển thị như hình vẽ sau, tham khảo file ví dụ với trang Web: https://hexed.it/     
  * Vùng đầu tiên là địa chỉ của ô nhớ, lần lược đánh số từ 0000 -FFFF
  * Vùng thứ hai là nội dung ô nhớ, dưới dạng hex (các ô nhớ không có dữ liệu sẽ được mặc định là FF 
  * Vùng thứ 3 là giá trị ASCII tương ứng với giá trị hex 
  * Vùng nhớ cố định là 64Kbytes, lớn hơn vùng nhớ này sẽ không cần hiển thị. 
  * Lưu ý là chương trình chỉ cần hiển thị dạng text đơn giản
  * Các file .hex mẫu.

  File Hex

  ![image](https://user-images.githubusercontent.com/61843403/184167892-ea025765-1300-4826-b333-deca0efa99d4.png)
  
  Yêu cầu hiển thị

  ![image](https://user-images.githubusercontent.com/61843403/184167920-aa25e75c-aecf-4a2b-bb5c-7d44d45254b5.png)

  2.	Kiểm tra xem phần Checksum (xem thêm ở phần lý thuyết) sau mỗi dòng bằng cách tính lại tổng các byte trong dòng đó sau đó tính phần bù (đảo bit và thêm 1). Kiểm  tra từng dòng nếu sai thoát chương trình.

  3.	Sau khí kiểm tra và hiển thị thì tách cách trường không phải Data ra khỏi file Hex sau đó bỏ ký tự xuống dòng (“/r/n”). Rồi xuất file mới dưới định dạng .bin (Raw Data)



  Lý thuyết : Giới thiệu về Intel hex file là một chuẩn format file hex thường dùng trong việc lưu trữ dữ liệu nhị phân trong các phần mềm làm việc với Vi điều khiển, là một phần dữ liệu của tệp thực thi .exe. Cấu trúc của Intel Hex file có thể được tham khảo ở trang sau:
  http://www.keil.com/support/docs/1584/
  https://en.wikipedia.org/wiki/Intel_HEX
  Trong các chương trình sử dụng trong vi điều khiển, chương trình dịch (compiler) thường dịch ra file hex (hoặc file .bin), các file này cho phép nói với vi điều khiển là các đoạn mã hex của chương trình sẽ nằm đâu trong bộ nhớ. Để đảm bảo tính chính xác của dữ liệu, Intel Hex luôn đưa ra kiểm tra check sum và nhiệm vụ của lập trình viên là đảm bảo luôn kiểm tra check sum cho mỗi dòng dữ liệu được đọc vào.


## Exercise 5: 

![image](https://user-images.githubusercontent.com/61843403/184165635-56699906-0839-4469-bdb8-b36545a76f9f.png)

## Exercise 6: 

![image](https://user-images.githubusercontent.com/61843403/184161689-870b2d07-a292-4e53-896c-3c118981d6ad.png)

