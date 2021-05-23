## SEMINARIO LKM

Para el entendimiento de los LKM he creado un ejemplo sencillo en el cual se muestra en los logs del kernel el nombre de la funcion a la que llama al realizar la carga y la descarga del módulo.

**Código**

```
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


```



Compilo el código con un makefile

**Código Makefile**


	obj-m+=hello.o

	all:
		make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) modules
	clean: 
		make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) clean	

![Imagen compilacion](https://github.com/MIGUE1999/PDIH/blob/main/S-LKM/Multimedia/Captura%20de%20pantalla%20de%202021-05-23%2016-05-15.png)


Cargo y elimino el codigo con los dos siguientes comandos mostrados en la foto


![Imagen carga y descarga modulo](https://github.com/MIGUE1999/PDIH/blob/main/S-LKM/Multimedia/Captura%20de%20pantalla%20de%202021-05-23%2016-14-00.png)




Compruebo los logs del kernel(comando tail) para ver si se han realizado las funciones correspondientes a la carga(insmod) y descarga del modulo(rmmod)

![Imagen Comprobacion](https://github.com/MIGUE1999/PDIH/blob/main/S-LKM/Multimedia/Captura%20de%20pantalla%20de%202021-05-23%2016-15-06.png)

Como podemos ver nos muestra en los logs dentro de que funcion está dependiendo de si se carga o si se descarga el modulo.




