/**
 * @file hello.c
 * @author Miguel Angel Tejada Ortigosa
 * @date 23 Mayo 2021
 * @brief Ejemplo de introduccion a los LKM
*/    

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Miguel Angel Tejada Ortigosa");
MODULE_DESCRIPTION("Un ejemplo que muestra el nombre de la funcion a la que se esta llamando");
MODULE_VERSION("0.1");


int inside_function_init(void)
{
	printk(KERN_ALERT "Dentro de la funcion %s ", __FUNCTION__);
	return 0;
}

void inside_function_exit(void)
{
	printk(KERN_ALERT "Dentro de la funcion %s ", __FUNCTION__);

}

module_init(inside_function_init);
module_exit(inside_function_exit);





