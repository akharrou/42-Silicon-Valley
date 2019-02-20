
/* 'rpn_calc' Header File*/

#ifndef RPN_CALC_H
# define RPN_CALC_H
 
#define IS_OP(c) (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
#define IS_SPACE(c) (c == '\t' || c == '\n' || c == ' ')
#define IS_DIGIT(c) (c >= '0' && c <= '9')

typedef struct	s_stack
{
	int					data;
	struct s_stack		*next;
}				t_stack;

int		ft_strlen(char *s);
char	*ft_strdup_range(char *str, int index, int end);
int		ft_issep(char c, char *seperators);
int		ft_wcount(char *s);
char	**ft_split(char *str);

#endif