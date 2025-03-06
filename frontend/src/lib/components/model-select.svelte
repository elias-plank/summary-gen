<script lang="ts">
    import { Label } from "$lib/components/ui/label";
    import * as Select from "@/components/ui/select";
    import { onMount } from "svelte";

    type Props = {
        model?: string;
    };

    let { model = $bindable() }: Props = $props();
    let models: Array<string> = $state([]);

    function fetchModels() {
        fetch("/summarize/models")
            .then((response) => response.json())
            .then((data) => {
                models = data.models;
                if (models.length === 1) {
                    model = models[0];
                }
            })
            .catch(() => (models = []));
    }

    onMount(() => {
        fetchModels();
    });
</script>

<div class="grid w-full max-w-sm items-center gap-1.5">
    <Label for="model">Model</Label>
    <Select.Root type="single" bind:value={model}>
        <Select.Trigger class="w-full">
            {model}
        </Select.Trigger>
        <Select.Content>
            <Select.Group>
                <Select.GroupHeading>Models</Select.GroupHeading>
                {#each models as m}
                    <Select.Item value={m} label={m} />
                {/each}
            </Select.Group>
        </Select.Content>
    </Select.Root>
</div>
