#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int ft_tens(int nb)
{
	int tens = 1;

	if (nb < 0)
		tens = -1;
	while (nb > 9 || nb < -9)
	{
		nb /= 10;
		tens *= 10;
	}
	return (tens);
}

void ft_put_zeros(int nb, int t)
{
	if (nb < t)
	{
		ft_putchar('0');
		ft_put_zeros(nb, t / 10);
	}
}

int ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return nb;
}

void ft_putnbr(int nb)
{
	int tens;

	if (nb < 0)
		ft_putchar('-');
	while (nb > 9 || nb < -9)
	{
		tens = ft_tens(nb);
		ft_putchar((nb / tens + '0'));
		nb %= ft_tens(nb);
		ft_put_zeros(ft_abs(nb), tens / 10);
	}
	if (nb < 0)
		nb = -nb;
	ft_putchar(nb + '0');
}

