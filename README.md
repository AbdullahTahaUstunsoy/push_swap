Bu proje, iki stack (yığın) kullanarak verilen sayı dizisini en az hamleyle sıralamayı amaçlayan bir algoritma projesidir. 42 School müfredatının bir parçası olarak, veri yapıları ve algoritmik verimlilik (Big O) üzerine odaklanır.

---

## Özellikler

- **Stack Operasyonları:** `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr` işlemlerinin optimizasyonu.
- **Akıllı Sıralama:** Küçük sayı grupları (3-5 sayı) için özel mantıklar ve büyük gruplar için verimli algoritmalar.
- **Hata Yönetimi:** Geçersiz girdiler, tekrarlanan sayılar veya sayı olmayan karakterler için gelişmiş kontrol.
- **Performans:** 100 ve 500 sayılık setlerde en düşük işlem sayısını hedefleyen optimizasyon.

---

## Teknik Kazanımlar

Bu proje sürecinde şu algoritma ve veri yapısı konularında derinleştim:
- **Algoritma Karmaşıklığı (Big O):** Zaman ve alan karmaşıklığını hesaplayarak en verimli yaklaşımı seçme.
- **Sıralama Algoritmaları:** Radix Sort, Turk Algorithm veya Mechanical Sort gibi yaklaşımların stack yapısına uyarlanması.
- **Veri Yapıları:** Stack yapısının C dilinde verimli yönetimi ve işaretçi (pointer) kullanımı.
- **Amortize Analiz:** Algoritma performansının farklı veri setleri üzerindeki analizi.

---

## Kurulum ve Kullanım

1. **Depoyu klonlayın:**
   ```bash
   git clone [https://github.com/AbdullahTahaUstunsoy/push_swap.git](https://github.com/AbdullahTahaUstunsoy/push_swap.git)
   cd push_swap
2. Derleme Yapın: make
3. Çalıştırın: ./push_swap 3 2 5 1 4
