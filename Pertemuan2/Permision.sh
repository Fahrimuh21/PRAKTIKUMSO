# Membuat file kosong
touch f1 f2 f3

# Melihat permission awal file f1
ls -l f1

# Mengubah permission f1 (metode simbolik)
chmod u+x f1     # menambah execute untuk user
chmod g-w f1     # menghapus write untuk group
chmod o-r f1     # menghapus read untuk others

# Melihat hasil perubahan
ls -l f1

# Mengubah permission menggunakan angka (octal)
chmod 751 f1     # user=rwx, group=rx, others=x
chmod 624 f2     # user=rw-, group=w-, others=r--
chmod 430 f3     # user=r--, group=wx-, others=---
