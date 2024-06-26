# ระบบฟาร์มอัตโนมัติ (Auto Farm System)

โครงการนี้เป็นระบบฟาร์มอัตโนมัติที่พัฒนาโดย NSTIOM ในปี 2024 ระบบนี้ช่วยให้ผู้เล่นสามารถฟาร์มทรัพยากรในเกมได้โดยอัตโนมัติ โปรดให้เครดิต NSTIOM หากคุณแจกจ่ายหรือสอนระบบนี้ต่อ

## คุณสมบัติ

- **การเปิด/ปิดฟาร์มอัตโนมัติ**: ผู้เล่นสามารถเปิดหรือปิดฟังก์ชั่นฟาร์มอัตโนมัติได้
- **การเดินอัตโนมัติ**: ระบบจะนำทางผู้เล่นไปยังจุดทรัพยากรเป้าหมายโดยอัตโนมัติ
- **การจัดการแอนิเมชั่น**: ระบบจะใช้แอนิเมชั่นที่เหมาะสมระหว่างการฟาร์มและการเดิน
- **การเก็บรวบรวมทรัพยากร**: ระบบจะเก็บทรัพยากรโดยอัตโนมัติและตรวจสอบการมีอยู่ของพื้นที่ในกระเป๋า

## การใช้งาน

### คำสั่ง

- **/autofarm**: เปิดหรือปิดฟังก์ชั่นฟาร์มอัตโนมัติ

### ฟังก์ชั่น

- **SetFacingPoint**: กำหนดทิศทางการหันหน้าของผู้เล่นไปยังจุดหนึ่ง
- **GetXYFromAngle**: คำนวณพิกัด X และ Y จากมุมและระยะทาง
- **GetAbsoluteAngle**: รับมุมที่เป็นบวกแบบสมบูรณ์
- **GetAngleToPoint**: รับมุมระหว่างจุดสองจุด
- **n_clear_auto_farm**: ปิดระบบฟาร์มอัตโนมัติและแสดงข้อความเมื่อกระเป๋าเต็ม
- **CMD:autofarm**: คำสั่งเปิดหรือปิดฟังก์ชั่นฟาร์มอัตโนมัติ
- **n_autowalk**: เดินอัตโนมัติไปยังจุดเป้าหมาย
- **n_taskloopStatAuto**: ลูปตรวจสอบสถานะฟาร์มอัตโนมัติ
- **OnPlayerDisconnect**: ปิดฟังก์ชั่นฟาร์มอัตโนมัติเมื่อผู้เล่นออกจากระบบ
- **OnPlayerKeyStateChange**: เริ่มการฟาร์มเมื่อผู้เล่นกดปุ่มที่กำหนด
- **n_AutoFarmGetStartwood**: เริ่มการฟาร์มไม้โดยอัตโนมัติ
- **OnProgressFinish**: เรียกใช้เมื่อการฟาร์มเสร็จสิ้น
- **PLAYER_WOOD_UNFREEZE**: ยกเลิกการแช่แข็งผู้เล่นเมื่อการฟาร์มไม้เสร็จสิ้นและแจกไอเทมไม้

## วิธีการทำงาน

1. ผู้เล่นใช้คำสั่ง `/autofarm` เพื่อเปิดหรือปิดฟังก์ชั่นฟาร์มอัตโนมัติ
2. ระบบจะนำทางผู้เล่นไปยังจุดทรัพยากรและเริ่มฟาร์มโดยใช้แอนิเมชั่นที่เหมาะสม
3. เมื่อกระเป๋าผู้เล่นเต็ม ระบบจะปิดฟาร์มอัตโนมัติและแจ้งเตือนผู้เล่น
4. หากผู้เล่นออกจากระบบ ระบบจะปิดฟังก์ชั่นฟาร์มอัตโนมัติโดยอัตโนมัติ

โปรดตรวจสอบให้แน่ใจว่าได้ให้เครดิต NSTIOM เมื่อคุณแจกจ่ายหรือสอนระบบนี้ต่อ ขอบคุณ!

[คลิปสอน](URL)

[Youtube](https://www.youtube.com/@NSTIOM)

[Discord Server](https://discord.gg/TQkptZCrSY)
