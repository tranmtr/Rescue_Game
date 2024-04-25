# Rescue Princesses
- Họ và tên: Dương Thái Trân
- Lớp: K68-J
- Mã sinh viên: 23020712

# Giới thiệu game
- `Rescue Princesses` là một game thể loại mê cung, vượt ải, hoàn thành thử thách. Bạn hãy cố gắng khám phá các mê cung, tìm ra chiếc bánh thần kì và giải cứu nàng công chúa bị lũ rồng "bắt cóc".
- Video trình bày: 

# Cấu trúc
## Menu
- Nền menu: chứa các nút trong menu.
- Nút `Start`: bắt đầu màn chơi mới hoặc tiếp tục màn chơi trước đó.
- Nút `Level`: chọn một màn chơi.
- Nút `How to play`: hướng dẫn về cách chơi.
- Nút `Quit`: thoát game.
- Nút `Loa`: bật/ tắt âm thanh.
- Nút `Next Level`: chuyển sang level tiếp theo khi chiến thắng.
- Nút `Play Again`: chơi lại level ngay khi vừa thua.
- Nút `Home`: chuyển về menu chính.

## Mê cung
### Các khối tạo thành mê cung
-  Khối `floor`: nơi nhân vật di chuyển.
-  Khối `wall`: không cho nhân vật di chuyển qua.
-  Khối `lava`: nơi chứa những con rồng hùng mạnh, chạm vào khối này nhân vật sẽ mất mạng ngay lập tức.
-  Khối `ice`: hồi máu cho nhân vật.
-  Khối `cake`: chứa chiếc bánh thần kì phá giải lời nguyền.
-  Khối `start`: nơi bắt đầu.
-  Khối `finish`: đích đến.
### Nhân vật, công chúa và rồng
-  `Figure`: nhân vật chính trong game, chứa sức mạnh băng giá tiêu diệt những con rồng.
-  `Princess`: nàng công chúa bị dính lời nguyền, cần chiếc bánh thành kì mới hóa giải được.
-  `Dragons`: những con rồng "bắt cóc" nàng công chúa, chứa trong mình sức mạnh ngọn lửa hỏa ngục cực kì nguy hiểm.

# Chức năng chính
- `Di chuyển`: sử dụng 4 phím điều hướng để di chuyển theo 4 hướng, tìm đường đi trong mê cung, né các cuộc tấn công của rồng, hồi máu khi cần thiết, ... 
- `Tấn công rồng`: sử dụng phím `space` để bắn ra đạn băng.
- `Lấy bánh, giải cứu`: chạm vào `cake` để lấy bánh. Khi có bánh, chạm vào `princess` để giải cứu.
- `Về đích`: đưa công chúa ra chạm vào khối `finish` dành chiến thắng.

# Nguồn tham khảo
## Code
- Lazy Foo

## Image
- `Dragon`: 
- `Figure`:
- `Princess`:
- `Block`:

## Music 
- Web: 
## Mê cung
- Web: 