<?php
/**
 * @file
 * Default theme implementation to present all user profile data.
 *
 * This template is used when viewing a registered member's profile page,
 * e.g., example.com/user/123. 123 being the users ID.
 *
 * Use render($user_profile) to print all profile items, or print a subset
 * such as render($user_profile['user_picture']). Always call
 * render($user_profile) at the end in order to print all remaining items. If
 * the item is a category, it will contain all its profile items. By default,
 * $user_profile['summary'] is provided, which contains data on the user's
 * history. Other data can be included by modules. $user_profile['user_picture']
 * is available for showing the account picture.
 *
 * Available variables:
 *   - $user_profile: An array of profile items. Use render() to print them.
 *   - Field variables: for each field instance attached to the user a
 *     corresponding variable is defined; e.g., $account->field_example has a
 *     variable $field_example defined. When needing to access a field's raw
 *     values, developers/themers are strongly encouraged to use these
 *     variables. Otherwise they will have to explicitly specify the desired
 *     field language, e.g. $account->field_example['en'], thus overriding any
 *     language negotiation rule that was previously applied.
 *
 * @see user-profile-category.tpl.php
 *   Where the html is handled for the group.
 * @see user-profile-item.tpl.php
 *   Where the html is handled for each item in the group.
 * @see template_preprocess_user_profile()
 *
 * @ingroup themeable
 */
?>
<div class="layout-profile">
  <div class="layout-inner">
    <div class="layout-element-alpha">
      <div class="layout-element-alpha-inner">
        <div class="content">
          <div class="content--image">
            <h1 class="field--title is-profile">
              <?php print render($user_profile['field_profile_name']); ?>
            </h1>
          </div>
          <div class="content--main">
            <h2 class="block--field-label"><?php print t('Contact');?></h2>
            <div class="block--field-label"><?php print t('Name'); ?></div><div><?php print $elements["#account"]->name; ?></div>
            <div class="block--field-label"><?php print t('Email'); ?></div><div><?php print $elements["#account"]->mail; ?></div>
            <?php if ($user->uid == $elements['#account']->uid) : ?>
              <div>
                <p></p>
                <p>
                  <a href="/ansoeg/teater-refusion" class="button"><?php print t('Apply for expense coverage') ?></a>
                  <a href="/admin/teater-refusion/ansoegninger/<?php print $elements['#account']->uid; ?>" class="button"><?php print t('View archived applications') ?></a>
                </p>
              </div>
            <?php endif; ?>
          </div>
          <div class="content--meta">
          </div>
        </div>
      </div>
    </div>
  </div>
</div>
