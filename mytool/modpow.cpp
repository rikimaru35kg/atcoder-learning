// Calculate mod(a^b, mod)
// a >= 0, b >= 0, mod > 0;
long long modpow(long long a, long long b, long long mod) {
	long long ans = 1;
	a %= mod;
	while (b > 0) {
		if ((b & 1) == 1) {
			ans = ans * a % mod;
		}
		a = a * a % mod;
		b = (b >> 1);
	}
	return ans;
}

// Calculate a^b
// a >= 0, b >= 0
long long spow(long long a, long long b) {
	long long ans = 1;
	while (b > 0) {
		if ((b & 1) == 1) {
			ans = ans * a;
		}
		a = a * a;
		b = (b >> 1);
	}
	return ans;
}
