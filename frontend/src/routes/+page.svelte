<script lang="ts">
    import ModelSelect from "@/components/model-select.svelte";
    import FileUpload from "@/components/file-upload.svelte";
    import { type UploadedFile } from "@/components/file-upload.svelte";
    import Button from "@/components/ui/button/button.svelte";

    let files: Array<UploadedFile> = $state([]);
    let model: string | undefined = $state(undefined);
</script>

<div class="hidden h-full flex-col md:flex">
    <div class="container h-full py-6">
        <div class="grid grid-flow-row-dense grid-cols-4">
            <div class="col-span-3">
                <FileUpload maxFiles={1} bind:files />
            </div>
            <div class="container flex flex-col gap-2">
                <ModelSelect bind:model />
                <Button>Transcribe</Button>
                <Button>Summarize</Button>
            </div>
        </div>
    </div>
</div>
