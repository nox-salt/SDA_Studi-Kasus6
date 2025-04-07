# SDA_Studi-Kasus6

Program ini saya buat berdasarkan ilustasi dosen Pak Wendy.

Sepanjang saya membuat program ini saya mengalami kesulitan ketika pertama kali membuat doubley linked list dimana struct untuk list KOTA memiliki tempat untuk menyimpan alamat yang nantinya menunjuk ke alamat struct list NAMA!
Program ini saya buat masih dengan tingkat kompleksitas yang sederhana dimana struct list kota yang berupa Double atau menyimpan alamat untuk struct KOTA sebelumnya dan struct KOTA setelahnya. Untuk struct NAMA, saya masih menggunakan konsep Single dimana struct NAMA hanya menyimpan alamat yang menuju ke struct NAMA setelahnya.

Pada awal proses pembuatan program ini, saya meminta bantuan chatGPT untuk menyediakan konseptual dan logika program yang akan saya buat lalu saya coba untuk membuatnya. Dengan cara ini saya dapat memahami konsep dari Double dan cara mengakses struct NAMA di dalam struct KOTA. Saya melakukan proses ini berulang kali selama 1 Hari lamanya dengan membuat file latihan dengan konsep yang sama sebelum kemudian memutuskan untuk membuat programnya langsung.

Saya menemukan bahwa sebuah struct selain bisa menyimpan alamat struct yang sama dengan tujuan menunjukkan struct sebelum dan sesudah, struct juga dapat menyimpan struct yang lain (beda isi) dan memungkinkan kita untuk mengakses data struct lain tersebut di dalam struct yang pertama.
