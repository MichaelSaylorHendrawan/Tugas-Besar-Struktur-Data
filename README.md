# Tugas-Besar-Struktur-Data
Topik yang kami pilih adalah pengelolaan data peserta dan data kejuaraan atau perlombaan. 
Dalam kasus ini, satu peserta bisa mengikuti lebih dari satu kejuaraan, dan satu kejuaraan juga 
bisa diikuti oleh banyak peserta. 
Karena itu, hubungan yang terbentuk adalah hubungan Many to Many.
Untuk mengimplementasikan kasus tersebut, kami menggunakan multi linked list. 
Data peserta disimpan menggunakan double linked list circular supaya memudahkan proses 
penambahan dan penghapusan data. 
Data kejuaraan disimpan menggunakan single linked list, karena akses datanya cukup satu arah. 
Sedangkan relasi antara peserta dan kejuaraan disimpan pada linked list relasi yang berisi pointer 
ke peserta dan kejuaraan.
