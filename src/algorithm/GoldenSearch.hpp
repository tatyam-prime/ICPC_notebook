// return {argmax, max}
// f は [l, r] 上で上に単峰であること
auto golden(double l, double r, auto f) {
    const double p = numbers::phi - 1;
    double r2 = lerp(l, r, p);
    auto fr = f(r2);
    rep(i, 0, 80) {  // phi^80 = 5e16
        double l2 = lerp(r, l, p);
        auto fl = f(l2);
        // maximize
        if (fl < fr) l = r, r = l2; 
        else r = r2, r2 = l2, fr = fl;
    }
    return pair{r2, fr};
}
