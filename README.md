# NewTypes
game c++/sdl2

Mô tả :

- Nhân vật chính sẽ tiêu diệt các đối thủ bằng cách gõ đúng các từ đại diện cho các đối thủ đó 
- Nhân vật chính sẽ bị tiêu diệt nếu bị các vật thể khác va chạm
- Có cơ chế tùy chọn bật / tắt nhạc nền , bật / tắt chế độ tự né vật thể khác
- Trò chơi sẽ kéo dài vô tận tùy vào độ kiên trì và trình độ của người chơi

Thuật toán :

- Xử lý đường đạn
- Xử lý va chạm
- Xử lý hiển thị nhân vật , quay theo hướng của đối thủ đang tiêu diệt
- Xử lý để nhân vật chính có thể tự né vật thể lạ
- Khi bị đạn va chạm thì đối thủ dịch lại một chút theo đúng hướng của đạn , giúp tăng thêm cơ hội cho người chơi
- Xử lý di chuyển ( có điều chỉnh tốc độ theo thời gian ) và va chạm của đối thủ , gai ( thứ mà sau khi đối thủ chết sẽ bắn ra )

Khác :

- Xử lý chuột ( trong phần menu trước khi chơi )
- Xử lý bàn phím ( trong toàn bộ quá trình trước , trong và sau khi chơi )
- Xử lý hiển thị gai ( đổi màu , xoay tròn theo thời gian )
