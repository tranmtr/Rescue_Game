# Rescue Princesses
- Họ và tên: Dương Thái Trân
- Lớp: K68-J
- Mã sinh viên: 23020712

# Giới thiệu game
- `Rescue Princesses` là một game thể loại mê cung, vượt ải, hoàn thành thử thách. Bạn hãy cố gắng khám phá các mê cung, tìm ra chiếc bánh thần kì và giải cứu nàng công chúa bị lũ rồng "bắt cóc".
- Video trình bày: [đây ](https://www.youtube.com/watch?v=rt7cdAKRb98).

# Cách tải game 
## Cách 1: Không bao gồm code
- Tải game (được nén thành file .zip ) tại [đây](https://github.com/tranmtr/Rescue_Game/releases/tag/published).
- Fle chỉ khoảng 30 MB nên tải rất nhanh.
- Sau khi tải về, giải nén vào một thư mục, bật Game_funny.exe lên và trải nghiệm.

## Cách 2: Bao gồm code
- Bước 1: Clone repo này về hoặc chọn Code -> Download Zip.
- Bước 2: Giải nén (đối với file zip), bật Game_funny.exe lên và trải nghiệm.

# Hướng dẫn chơi
- Sử dụng các phím mũi tên `←`, `→`, `↑`, `↓`, để di chuyển theo các hướng.
- Sử dụng phím `SPACE` để tấn công.
- Trình tự giải cứu: `Cake`->`Princess`->`Goal`.

# Cấu trúc, các thành phần trong game
## 1. Nhân vật chính
### Knight
![Knight_Image](https://github.com/tranmtr/Rescue_Game/blob/main/Game_funny/File_Image/image_Figure/figure.pngy.png) 
- Bạn sẽ điều khiển nhân vật này di chuyển tìm đường đi trong mê cung, tránh né những quả cầu lửa, tấn công rồng và giải cứu công chúa.

## 2. Các đối tượng tương tác với nhân vật chính
### Dragon
![Dragon_Image](https://github.com/tranmtr/Rescue_Game/blob/main/Game_funny/File_Image/image_Figure/dragon.png)
- Tấn công nhân vật bằng những quả cầu lửa với sát thương lớn.
### Princess
![Princess_Image](https://github.com/tranmtr/Rescue_Game/blob/main/Game_funny/File_Image/image_Figure/princess.png)
- Đang bị dính lời nguyên, cần chiếc bánh ngọt trong mê cung để hóa giải.
## 3. Các khối trong mê cung
|        | Tên | Chức năng  |
|:-------|:------:|-------|
|  ![start_Image](https://github.com/tranmtr/Rescue_Game/blob/main/Game_funny/File_Image/image_Maze/start_mau_ghi(80_80).jpg)  |  Start  |   Vị trí bắt đầu của nhân vật  |
|  ![finish_image](https://github.com/tranmtr/Rescue_Game/blob/main/Game_funny/File_Image/image_Maze/finish_mau_xanh_la_cay.jpg)  |  Finish  |   Đích đến   |
| ![lava_image](https://github.com/tranmtr/Rescue_Game/blob/main/Game_funny/File_Image/image_Maze/lavaPixel(80_80).jpg) | Lava  | Nơi rồng lửa ngự trị, nếu chạm vào nhân vật sẽ chết ngay lập tức  |
| ![Ice_image](https://github.com/tranmtr/Rescue_Game/blob/main/Game_funny/File_Image/image_Maze/ice_block_slow.jpg) | IceIce | Nơi hồi máu cho nhân vật  |
| ![Cake_Image](https://github.com/tranmtr/Rescue_Game/blob/main/Game_funny/File_Image/image_Maze/cake_fast(80_80).jpg) | Cake | Nơi lấy chiếc bánh thần kì |
| ![Floor_ImageImage](https://github.com/tranmtr/Rescue_Game/blob/main/Game_funny/File_Image/image_Maze/nen_mau_tim_2(thu_nho_2).jpg) | Floor | Nơi nhân vật di chuyển  |
| ![Wall_Image](https://github.com/tranmtr/Rescue_Game/blob/main/Game_funny/File_Image/image_Maze/wall.png) | Wall | Ngăn cản sự di chuyển của nhân vật |
## Chiến thắng và thất bại
### Chiến thắng 
![Victory_Image](https://github.com/tranmtr/Rescue_Game/blob/main/Game_funny/File_Image/image_Maze/victory_tach_nen.png)
- Khi đến đích cùng với công chúa bạn sẽ chiến thắng.

### Thất bại
![Defeat_Image](https://github.com/tranmtr/Rescue_Game/blob/main/Game_funny/File_Image/image_Maze/defeat_tach_nen.png)
- Khi nhân vật chạm vào dung nham hoặc bị bắn chết.

## 4. Menu
- Màn hình chính: 
![Man_hinh_chinh](https://github.com/tranmtr/Rescue_Game/blob/main/Game_funny/File_Image/image_Menu/MENU_BACKGROUD.png)
- Nút `next level` : sử dụng khi chiến thắng
![next](https://github.com/tranmtr/Rescue_Game/blob/main/Game_funny/File_Image/image_Menu/mui_ten_next_level.png)
- Nút `Play Again`: sử dụng khi thua cuộc
![again](https://github.com/tranmtr/Rescue_Game/blob/main/Game_funny/File_Image/image_Menu/level_again.png)
- Nút `Back home`: sử dụng khi muốn quay lại menu 
![Back](https://github.com/tranmtr/Rescue_Game/blob/main/Game_funny/File_Image/image_Menu/way_back_home.png)
# Kĩ thuật lập trình 
## Phát triển trên nền tảng
- IDE Code::Blocks 20.03
- Ngôn ngữ lập trình C++
- Thư viện SDL2 
- Extension của SDL2:
	- SDL_Image: Hỗ trợ xử lý hình ảnh 
	- SDL_Mixer: Hỗ trợ xử lý âm thanh
	- SDL_TTF: Hỗ trợ xử lý font

## Các kĩ thuật lập trình
- Vòng lặp, cấu trúc rẽ nhánh,...
- Con trỏ, vector, string,...
- Class, struct, ...
- Đọc viết file: fstream
- Tách file quản lý code.
- Kỹ thuật duyệt mảng, ...
- Các kĩ thuật, syntax của SDL
- Kĩ thuật giải phóng bộ nhớ

# Về source code game
- File header.h
    - Khai báo các thư viện có sẵn trong C++, SDL2
    - Các define sử dụng trong các hàm 
    - Các thông số cố định sử dụng trong game 
- File LTexture: render hình ảnh, chữ lên màn hình.
- File Figure: tạo ra nhân vật với các chỉ số, sự chuyển động, animation, tấn công, ...
- File Ice: tạo ra đạn của nhân vật
- File Dragon: tạo ra những con rồng
- File chooseLevel: cài đặt các thông số cho các màn chơi khác nhau.
- File load_Mouse: sự kiện chuột tương tác trực tiếp với Menu.
- File checkCollision: kiểm tra sự va chạm của các khối, đối tượng theo hình chữ nhật.
- File init_and_close: khởi tạo cửa sổ, màn hình,... khi bắt đầu, đồng thời giải phóng bộ nhớ khi kết thúc.

# Về đồ họa:
- Image

    - Knight, Princess, ice, fire, victory, finish, các khối trong mê cung, ... : [pinterest ](https://pt.pinterest.com/)
    - Dragon: [roomrecess](https://www.roomrecess.com/games/BattleBuddies/Mobs/)
- Music:
    - chunk : [pixabay](https://pixabay.com/vi/sound-effects/) 
    - Nhạc nền: [youtube](https://www.youtube.com/watch?v=C6Ne8aV9GEk)
- 
# Nguồn tham khảo 

- Các syntax SDL cơ bản: [Lazyfoo](https://lazyfoo.net/tutorials/SDL/)