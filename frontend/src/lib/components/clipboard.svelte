<script lang="ts">
    import { Copy } from "lucide-svelte";

    type Props = {
        size: number;
        content: string;
        disabled: boolean;
    };

    let open = $state(false);
    let { size, content, disabled }: Props = $props();

    function handleCopy() {
        navigator.clipboard.writeText(content);
        setInterval(() => {
            open = false;
        }, 3000);
    }
</script>
