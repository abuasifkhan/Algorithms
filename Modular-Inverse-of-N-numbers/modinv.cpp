// Modular Inverse of N numbers in O(1)
int inv[SIZE];
inv[1] = 1;
for ( int i = 2; i <= n; i++ ) {
    inv[i] = (-(m/a) * inv[m%a] ) % m;
    inv[i] = inv[i] + m;
}
