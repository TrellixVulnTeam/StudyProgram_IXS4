#ifndef __DRV_MMZ_USERDEV_IOCTL_H__
#define __DRV_MMZ_USERDEV_IOCTL_H__

#define HIL_MMZ_NAME_LEN 32
#define HIL_MMB_NAME_LEN 16

/* remove pclint waring anonymous struct or union */
/*lint -save -e1504 */
/*lint -save -e657  */
/*lint -save -e658  */


struct mmb_info {
	HI_PHYS_ADDR_T phys_addr;	/* phys-memory address */
	unsigned int align;		/* if you need your phys-memory have special align size */
	unsigned int size;		/* length of memory you need, in bytes */
	unsigned int order;

	HI_VIRT_ADDR_T mapped;			/* userspace mapped ptr */

	union {
		struct {
			unsigned int prot  :8;	/* PROT_READ or PROT_WRITE */
			unsigned int flags :12;/* MAP_SHARED or MAP_PRIVATE */

#ifdef __KERNEL__
			unsigned int reserved :8; /* reserved, do not use */
			unsigned int delayed_free :1; 
			unsigned int map_cached :1; 
#ifdef MMZ_V2_SUPPORT
            unsigned int mmb_type :2; /*0: not share, 1 :share and in current program list , 2: share and in share list*/
#endif
#endif
		};
		unsigned int w32_stuf;
	};

	char mmb_name[HIL_MMB_NAME_LEN];
	char mmz_name[HIL_MMZ_NAME_LEN];
	unsigned int gfp;		/* reserved, do set to 0 */

#ifdef __KERNEL__
	int map_ref;
	int mmb_ref;

	struct list_head list;
	hil_mmb_t *mmb;
#ifdef MMZ_V2_SUPPORT
    pid_t pid;
    struct list_head share_list;
#endif
#endif
};
/*lint -restore */

struct dirty_area {
    HI_PHYS_ADDR_T dirty_phys_start;    /* dirty physical address */
    HI_VIRT_ADDR_T dirty_virt_start; /* dirty virtual  address,
                       must be coherent with dirty_phys_addr */
    unsigned int dirty_size;
};

#define IOC_MMB_ALLOC                   _IOWR('m', 10,  struct mmb_info)
#define IOC_MMB_ATTR                     _IOR ('m', 11,  struct mmb_info)
#define IOC_MMB_FREE                     _IOW ('m', 12,  struct mmb_info)
#define IOC_MMB_ALLOC_V2             _IOWR('m', 13,  struct mmb_info)
#define IOC_MMB_ALLOC_SHARE       _IOWR('m', 14,  struct mmb_info)
#define IOC_MMB_ALLOC_SHM_COM  _IOWR('m', 15,  struct mmb_info)
#define IOC_MMB_GET_SHM_COM      _IOWR('m', 16,  struct mmb_info)
#define IOC_MMB_FORCE_FREE          _IOW ('m', 17,  struct mmb_info)

#define IOC_MMB_USER_REMAP			_IOWR('m', 20,  struct mmb_info)
#define IOC_MMB_USER_REMAP_CACHED 	_IOWR('m', 21,  struct mmb_info)
#define IOC_MMB_USER_UNMAP			_IOWR('m', 22,  struct mmb_info)
#define IOC_MMB_USER_GETPHYADDR		_IOWR('m', 23,  struct mmb_info)


#define IOC_MMB_ADD_REF				_IO('r', 30)	/* ioctl(file, cmd, arg), arg is mmb_addr */
#define IOC_MMB_DEC_REF				_IO('r', 31)	/* ioctl(file, cmd, arg), arg is mmb_addr */

#define IOC_MMB_FLUSH_DCACHE		_IO('c', 40)

#define IOC_MMB_FLUSH_DCACHE_DIRTY        _IOW('d', 50, struct dirty_area)

#define IOC_MMB_TEST_CACHE			_IOW('t',  11,  struct mmb_info)



#endif

