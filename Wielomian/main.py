class Wielomian:
    def __init__(self):
        self.stopien = 0
        self.wspolczynniki = [0]

    def __init__(self, wielomian):
        self.stopien = wielomian.stopien
        self.wspolczynniki = wielomian.wspolczynniki

    def __init__(self, liczba, tablica):
        self.stopien = liczba
        self.wspolczynniki = tablica

    def __add__(self, other):
        if self.stopien >= other.stopien:
            for i in range(0, other.stopien):
                self.wspolczynniki[i] = self.wspolczynniki[i] + other.wspolczynniki[i]
            return Wielomian(self.stopien, self.wspolczynniki)
        else:
            for i in range(0, self.stopien):
                other.wspolczynniki[i] = self.wspolczynniki[i] + other.wspolczynniki[i]
            return Wielomian(other.stopien, other.wspolczynniki)

    def __sub__(self, other):
        if self.stopien >= other.stopien:
            for i in range(0, other.stopien):
                self.wspolczynniki[i] = self.wspolczynniki[i] - other.wspolczynniki[i]
            return Wielomian(self.stopien, self.wspolczynniki)
        else:
            for i in range(0, self.stopien):
                other.wspolczynniki[i] = self.wspolczynniki[i] - other.wspolczynniki[i]
            return Wielomian(other.stopien, other.wspolczynniki)

    def __mul__(self, other):
        wspolczynniki = [0]
        stopien = self.stopien + other.stopien
        for i in range(0, self.stopien):
            for j in range(0, other.stopien):
                wspolczynniki[i + j] = wspolczynniki[i + j] + self.wspolczynniki[i] * other.wspolczynniki[j]
        return Wielomian(stopien, wspolczynniki)

    def __getitem__(self, item):
        return self.wspolczynniki[item]

    def __setitem__(self, key, value):
        self.wspolczynniki[key] = value

    def __call__(self, a):
        if self.stopien == 0:
            return self.wspolczynniki[0]
        elif self.stopien == 1:
            return self.wspolczynniki[0] + self.wspolczynniki[1] * a
        else:
            x = self.wspolczynniki[self.stopien] * a + self.wspolczynniki[self.stopien - 1]
            for i in self.wspolczynniki[::-1]:
                if i != self.wspolczynniki[self.stopien] and i != self.wspolczynniki[self.stopien - 1]:
                    x = i + a * x
            return x

if __name__ == '__main__':
    a = Wielomian(2,[1,2,3])
    b = Wielomian(3,[1,2,3,4])
    c = a + b
    print (str(c.wspolczynniki) + " " + str(c.stopien))























