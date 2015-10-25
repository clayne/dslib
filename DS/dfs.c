#include "tree.h"
#include "stack.h"

int search_DFS(tree_pp root, int val)
{
	int ret = FALSE;
	tree_p node = NULL;
	stack_p stack = NULL;

	if (!root || !*root) {
		printf("root node is NULL.\n");
		return FALSE;
	}


	stack = get_stack();
	if (!push(stack, *root)) {
		printf("push failed.\n");
		destroy_stack(stack);
		return FALSE;
	}

	while ((node = pop(stack)) != NULL) {
		if (node->data == val) {
			log(INFO, "FOUND %d\n", val);
			ret = TRUE;
			break;
		}

		log(DEBUG, "tracking...\n");

		if (node->left) {
			if (!push(stack, node->left)) {
				printf(" push()failed.\n");
				ret = FALSE;
				break;
			}
		}

		if (node->right) {
			if (!push(stack, node->right)) {
				printf(" push()failed.\n");
				ret = FALSE;
				break;
			}
		}
	}

	destroy_stack(stack);
	return ret;
}
