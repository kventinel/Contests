var n = readline();
var arr = readline().split( ).map(v => +v.trim());
var a = [];
var k = 0;
for (i = 0; i < n; i++) {
    if (k < a.length) {
        a[k] = arr[i];
        ++k;
    } else {
        a.push(arr[i]);
        ++k;
    }
    while (k > 1) {
        if (a[k - 1] == a[k - 2]) {
            ++a[k - 2];
            --k;
        } else {
            break;
        }
    }
}
print(k)
for (i = 0; i < k; ++i) {
    print(a[i])
}
